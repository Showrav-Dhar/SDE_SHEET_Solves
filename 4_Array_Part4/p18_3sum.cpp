// // Brute force

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> nums = {-1, 0, 1, 2, -1, -4};

//     set<vector<int>> ans;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             for (int k = j + 1; k < nums.size(); k++)
//             {
//                 if (nums[i] + nums[j] + nums[k] == 0)
//                 {
//                     vector<int> temp = {nums[i], nums[j], nums[k]};
//                     sort(temp.begin(), temp.end());
//                     ans.insert(temp);
//                 }
//             }
//         }
//     }

//     vector<vector<int>> ans2(ans.begin(), ans.end());

//     for (auto it : ans2)
//     {
//         for (auto i : it)
//         {
//             cout << i << " ";
//         }
//         cout << endl;
//     }

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// Better -

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> nums = {-1, 0, 1, 2, -1, -4};

//     set<vector<int>> temp_ans;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         set<int> hash_set;

//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             int third_item = -(nums[i] + nums[j]);
//             if (hash_set.find(third_item) != hash_set.end())
//             {
//                 vector<int> temp = {nums[i], nums[j], third_item};
//                 sort(temp.begin(), temp.end());
//                 temp_ans.insert(temp);
//             }

//             hash_set.insert(nums[j]);
//         }
//     }

//     vector<vector<int>> ans(temp_ans.begin(), temp_ans.end());

//     for (auto it : ans)
//     {
//         for (auto i : it)
//         {
//             cout << i << " ";
//         }
//         cout << endl;
//     }

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }


#include <bits/stdc++.h>
using namespace std;

/**
 * 
 * APPROACH: Two Pointers (After Sorting)
 * 1. Sort array first - enables duplicate handling and two-pointer technique
 * 2. Fix first element, use two pointers for remaining two elements
 * 3. Skip duplicates at all levels to ensure uniqueness
 * 
 * Time Complexity: O(n²) - O(n log n) sort + O(n²) two-pointer loops
 * Space Complexity: O(1) - excluding output array
 * 
 * WHY THIS BEATS HASH MAP APPROACH:
 * - No extra space for hash map
 * - Natural duplicate handling through sorting
 * - More intuitive duplicate skipping
 * - Industry standard solution
 */

vector<vector<int>> threeSum(vector<int>& nums) 
{
    // STEP 1: Sort for two-pointer technique and easy duplicate handling
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> result;
    int n = nums.size();
    
    // STEP 2: Fix first element (nums[i]), find two others with two pointers
    for (int i = 0; i < n ; i++) 
    {
        // DUPLICATE SKIP: Skip same values for first element
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        // STEP 3: Two pointers for remaining elements
        int j = i + 1;           // Start after current element // left
        int k = n - 1;          // Start from end // right
        
        while (j < k) 
        {
            int currentSum = nums[i] + nums[j] + nums[k];
            
            if (currentSum < 0) {
                // Sum too small, need larger number
                j++;
            }
            else if (currentSum > 0) {
                // Sum too large, need smaller number  
                k--;
            }
            else {
                // FOUND TRIPLET: currentSum == 0
                result.push_back({nums[i], nums[j], nums[k]});
                
                // MOVE BOTH POINTERS and skip duplicates
                j++;
                k--;
                
                // CRITICAL: Skip duplicate values for second element
                while (j < k && nums[j] == nums[j - 1]) {
                    j++;
                }
                
                // CRITICAL: Skip duplicate values for third element  
                while (j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
            }
        }
    }
    
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // TEST CASE
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    vector<vector<int>> result = threeSum(nums);

    // OUTPUT RESULTS
    cout << "Unique triplets that sum to 0:" << endl;
    for (const auto& triplet : result) 
    {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    cout << "Total triplets found: " << result.size() << endl;

    cerr << "Time elapsed: " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << endl;
    
    return 0;
}

/**
 * ALGORITHM WALKTHROUGH:
 * Input: [-1, 0, 1, 2, -1, -4]
 * After sort: [-4, -1, -1, 0, 1, 2]
 * 
 * i=0, nums[i]=-4: j=1, k=5
 *   sum = -4 + (-1) + 2 = -3 < 0 → j++
 *   sum = -4 + (-1) + 2 = -3 < 0 → j++  
 *   sum = -4 + 0 + 2 = -2 < 0 → j++
 *   sum = -4 + 1 + 2 = -1 < 0 → j++
 *   j >= k, exit
 * 
 * i=1, nums[i]=-1: j=2, k=5
 *   sum = -1 + (-1) + 2 = 0 ✓ → Found: [-1, -1, 2]
 *   Skip duplicates, continue...
 * 
 * i=2: nums[2] == nums[1], skip duplicate
 * 
 * i=3, nums[i]=0: j=4, k=5  
 *   sum = 0 + 1 + 2 = 3 > 0 → k--
 *   j >= k, exit
 * 
 * Result: [[-1, -1, 2], [-1, 0, 1]]
 * 
 * KEY INSIGHTS FOR INTERVIEWS:
 * 
 * 1. SORTING ENABLES TWO POINTERS:
 *    - Can move pointers based on sum comparison
 *    - Natural ordering for duplicate detection
 * 
 * 2. THREE LEVELS OF DUPLICATE HANDLING:
 *    - First element: Skip if same as previous
 *    - Second element: Skip after finding solution
 *    - Third element: Skip after finding solution
 * 
 * 3. WHY THIS IS O(n²):
 *    - Outer loop: O(n)
 *    - Inner two-pointer: O(n) per iteration
 *    - Total: O(n²)
 * 
 * 4. EDGE CASES HANDLED:
 *    - Empty array or length < 3
 *    - All positive/negative numbers
 *    - Many duplicates
 *    - Array already sorted
 * 
 * FOLLOW-UP VARIATIONS:
 * - 3Sum Closest (find triplet closest to target)
 * - 4Sum (extend to quadruplets)
 * - 3Sum Smaller (count triplets with sum < target)
 */