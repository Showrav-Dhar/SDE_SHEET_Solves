
/**
 * PROBLEM: 4Sum (LeetCode 18)
 * Find all unique quadruplets that sum to target
 *
 **/

// Bruteforce -

// #include <bits/stdc++.h>
// using namespace std;
// // Bruteforce - o(n^4)
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> ara = {1, 0, -1, 0, -2, 2};
//     int target = 0;

//     set<vector<int>> ans;

//     for (int i = 0; i < ara.size(); i++)
//     {
//         for (int j = i + 1; j < ara.size(); j++)
//         {
//             for (int k = j + 1; k < ara.size(); k++)
//             {
//                 for (int l = k + 1; l < ara.size(); l++)
//                 {
//                     if (ara[i] + ara[j] + ara[k] + ara[l] == target)
//                     {
//                         vector<int> temp = {ara[i], ara[j], ara[k], ara[l]};
//                         sort(temp.begin(), temp.end());
//                         ans.insert(temp);
//                     }
//                 }
//             }
//         }
//     }

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

// --- >>>> BETTER <<<<< ---- ///

// #include <bits/stdc++.h>
// using namespace std;

// /**
//  * PROBLEM: 4Sum (LeetCode 18)
//  * Find all unique quadruplets that sum to target
//  *
//  * CURRENT APPROACH: Triple Loop + Hash Set
//  * Fix first 3 elements, use hash set to find 4th element
//  *
//  * ALGORITHM BREAKDOWN:
//  * 1. Three nested loops to fix first three elements (i, j, k)
//  * 2. For each triplet, calculate required 4th element
//  * 3. Use hash set to check if 4th element exists in remaining elements
//  * 4. Sort each quadruplet and use set to eliminate duplicates
//  *
//  * Time Complexity: O(n³) - three nested loops
//  * Space Complexity: O(n) - hash set + result storage
//  */

// vector<vector<int>> fourSum(vector<int> &nums, int target)
// {
//     int len = nums.size();

//     // Using set to automatically handle duplicate quadruplets
//     set<vector<int>> temp_ans;

//     // OUTER LOOP: Fix first element (i)
//     for (int i = 0; i < len; i++)
//     {
//         // MIDDLE LOOP: Fix second element (j)
//         for (int j = i + 1; j < len; j++)
//         {
//             // HASH SET: Store elements we've seen for current (i,j) pair
//             // CRITICAL: Reset for each (i,j) pair to avoid using elements from wrong positions
//             set<long long int> hash_set;

//             // INNER LOOP: Fix third element (k)
//             for (int k = j + 1; k < len; k++)
//             {
//                 // CALCULATE: Sum of first three elements
//                 // OVERFLOW PROTECTION: Cast to long long before arithmetic
//                 long long int three_sum = (long long int)nums[i] +
//                                           (long long int)nums[j] +
//                                           (long long int)nums[k];

//                 // FIND: What 4th element do we need?
//                 long long int fourth_item = target - three_sum;

//                 // CHECK: Does required 4th element exist in our hash set?
//                 if (hash_set.find(fourth_item) != hash_set.end())
//                 {
//                     // FOUND QUADRUPLET: Create and normalize it
//                     vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth_item};

//                     // NORMALIZE: Sort to handle duplicates consistently
//                     sort(temp.begin(), temp.end());

//                     // STORE: Set automatically handles duplicates
//                     temp_ans.insert(temp);
//                 }

//                 // ADD: Current element to hash set for future iterations
//                 // IMPORTANT: Add nums[k], not fourth_item!
//                 hash_set.insert(nums[k]);
//             }
//         }
//     }

//     // CONVERT: Set to vector for return (LeetCode expects vector)
//     vector<vector<int>> ans(temp_ans.begin(), temp_ans.end());
//     return ans;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     // TEST CASE: Expected quadruplets that sum to 0
//     vector<int> ara = {1, 0, -1, 0, -2, 2};

//     vector<vector<int>> ans = fourSum(ara, 0);

//     cout << "Quadruplets that sum to 0:" << endl;
//     for (auto it : ans)
//     {
//         cout << "[";
//         for (int i = 0; i < it.size(); i++)
//         {
//             cout << it[i];
//             if (i < it.size() - 1)
//                 cout << ", ";
//         }
//         cout << "]" << endl;
//     }

//     cout << "Total quadruplets: " << ans.size() << endl;

//     cerr << "Time elapsed: " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << endl;

//     return 0;
// }

// /**
//  * DETAILED ALGORITHM WALKTHROUGH:
//  * Input: [1, 0, -1, 0, -2, 2], target = 0
//  *
//  * i=0, nums[i]=1:
//  *   j=1, nums[j]=0:
//  *     hash_set = {}
//  *     k=2, nums[k]=-1: three_sum=1+0+(-1)=0, fourth_item=0-0=0
//  *       hash_set.find(0) == end() (not found)
//  *       hash_set.insert(-1) → hash_set = {-1}
//  *     k=3, nums[k]=0: three_sum=1+0+0=1, fourth_item=0-1=-1
//  *       hash_set.find(-1) != end() (found!)
//  *       temp = {1, 0, 0, -1} → sort → {-1, 0, 0, 1}
//  *       temp_ans.insert({-1, 0, 0, 1})
//  *       hash_set.insert(0) → hash_set = {-1, 0}
//  *     k=4, nums[k]=-2: three_sum=1+0+(-2)=-1, fourth_item=0-(-1)=1
//  *       hash_set.find(1) == end() (not found)
//  *       hash_set.insert(-2) → hash_set = {-1, 0, -2}
//  *     k=5, nums[k]=2: three_sum=1+0+2=3, fourth_item=0-3=-3
//  *       hash_set.find(-3) == end() (not found)
//  *       hash_set.insert(2) → hash_set = {-1, 0, -2, 2}
//  *
//  * ... (continue for all i, j combinations)
//  *
//  * STRENGTHS OF THIS APPROACH:
//  *
//  * ✅ OVERFLOW PROTECTION:
//  *    - Uses long long for intermediate calculations
//  *    - Prevents integer overflow issues
//  *
//  * ✅ DUPLICATE HANDLING:
//  *    - sort() normalizes each quadruplet
//  *    - set<vector<int>> automatically removes duplicates
//  *
//  * ✅ CLEAN LOGIC:
//  *    - Easy to understand and implement
//  *    - Hash set provides O(1) lookup
//  *
//  * ✅ CORRECT INDEX MANAGEMENT:
//  *    - i < j < k < fourth_element_index (implicitly)
//  *    - No element reuse issues
//  *
//  * POTENTIAL OPTIMIZATIONS:
//  *
//  * ⚠️ COMPLEXITY: O(n³) vs optimal O(n²) with sorting + two pointers
//  *
//  * ⚠️ SPACE USAGE: Multiple sets (hash_set recreated each iteration)
//  *
//  * ⚠️ CACHE EFFICIENCY: Hash operations vs array access patterns
//  *
//  * ALTERNATIVE APPROACH (Industry Standard):
//  * 1. Sort array first
//  * 2. Two outer loops for first two elements
//  * 3. Two pointers for remaining two elements
//  * 4. Skip duplicates at each level
//  * 5. Achieves O(n³) time, better constant factors
//  *
//  * INTERVIEW FOLLOW-UPS:
//  * - "Can you optimize to O(n²)?" (No, proven lower bound)
//  * - "How would you handle k-sum for arbitrary k?" (Recursion/generalization)
//  * - "What if we need count instead of actual quadruplets?" (Same approach, count++)
//  * - "Memory constraints - can you reduce space usage?" (Two-pointer approach)

//  */

// --- >>>> OPTIMAL <<<<< ---- ///
#include <bits/stdc++.h>
using namespace std;

/**
 * PROBLEM: 4Sum (LeetCode 18) - Two Pointer Approach
 * Find all unique quadruplets that sum to target
 * 
 * APPROACH: Sort + Two Nested Loops + Two Pointers
 * 1. Sort array for duplicate handling and two-pointer technique
 * 2. Fix first two elements with nested loops
 * 3. Use two pointers for remaining two elements
 * 4. Skip duplicates at all four levels
 * 
 * Time Complexity: O(n³) - optimal for 4Sum
 * Space Complexity: O(1) - excluding output array
 */

vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();
    
    // OUTER LOOP: Fix first element
    for (int i = 0; i < n - 3; i++) 
    {
        // SKIP DUPLICATES: First element
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        // MIDDLE LOOP: Fix second element  
        for (int j = i + 1; j < n - 2; j++) 
        {
            // SKIP DUPLICATES: Second element
            // CRITICAL FIX: Check j > i + 1, not j > 0
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            
            // TWO POINTERS: For third and fourth elements
            int left = j + 1; // k 
            int right = n - 1; // l 
            
            while (left < right) 
            {
                // CALCULATE SUM: Use long long to prevent overflow
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                
                if (sum > target) {
                    right--;                    // Sum too large, decrease right
                }
                else if (sum < target) {
                    left++;                     // Sum too small, increase left  
                }
                else {
                    // FOUND QUADRUPLET
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    
                    // MOVE BOTH POINTERS
                    left++;
                    right--;
                    
                    // SKIP DUPLICATES: Third element
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    
                    // SKIP DUPLICATES: Fourth element
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
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

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    
    vector<vector<int>> result = fourSum(nums, target);
    
    cout << "Unique quadruplets that sum to " << target << ":" << endl;
    for (const auto& quad : result) 
    {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    cout << "Total quadruplets: " << result.size() << endl;

    cerr << "Time elapsed: " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << endl;
    
    return 0;
}

/**
 
 * 🚫 CRITICAL step 1: Wrong duplicate check condition
 * Fixed:    if (j > i + 1 && nums[j] == nums[j - 1])
 * 
 * 🚫 CRITICAL step 2: Incorrect pointer movement in else block
 * Original: Always moved k++ and l-- after finding solution
 * Fixed:    Only move pointers inside the else (sum == target) block
 * 
 * 🚫 CRITICAL step 3: Variable naming inconsistency
 * Original: Used ara[k] and ara[l] but variables named left/right
 * Fixed:    Consistent variable naming throughout
 * 
 * ALGORITHM WALKTHROUGH:
 * Input: [1, 0, -1, 0, -2, 2], target = 0
 * After sort: [-2, -1, 0, 0, 1, 2]
 * 
 * i=0, nums[i]=-2:
 *   j=1, nums[j]=-1: left=2, right=5
 *     sum = -2 + (-1) + 0 + 2 = -1 < 0 → left++
 *     sum = -2 + (-1) + 0 + 2 = -1 < 0 → left++  
 *     sum = -2 + (-1) + 1 + 2 = 0 ✓ → Found: [-2, -1, 1, 2]
 *     Move pointers and skip duplicates...
 * 
 * i=0, nums[i]=-2:
 *   j=2, nums[j]=0: left=3, right=5
 *     sum = -2 + 0 + 0 + 2 = 0 ✓ → Found: [-2, 0, 0, 2]
 *     Continue...
 * 
 * i=1, nums[i]=-1:
 *   j=2, nums[j]=0: left=3, right=5  
 *     sum = -1 + 0 + 0 + 2 = 1 > 0 → right--
 *     sum = -1 + 0 + 0 + 1 = 0 ✓ → Found: [-1, 0, 0, 1]
 * 
 * Final Result: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
 * 
 * WHY TWO-POINTER APPROACH IS SUPERIOR:
 * 
 * ✅ BETTER CONSTANTS: No hash operations, pure array access
 * ✅ CACHE FRIENDLY: Sequential memory access patterns  
 * ✅ NATURAL DUPLICATES: Sorting enables easy duplicate skipping
 * ✅ INDUSTRY STANDARD: What FAANG expects to see
 * ✅ SPACE EFFICIENT: O(1) extra space vs O(n) for hash approach
 * 
 * DUPLICATE HANDLING STRATEGY:
 * 
 * Level 1 (i): Skip if nums[i] == nums[i-1] and i > 0
 * Level 2 (j): Skip if nums[j] == nums[j-1] and j > i+1  
 * Level 3 (left): Skip after finding solution
 * Level 4 (right): Skip after finding solution
 * 
 * The key insight is that we only skip duplicates AFTER we've used 
 * the first occurrence of each value at each level.
 * 
 * COMPLEXITY ANALYSIS:
 * - Time: O(n³) - two nested loops × two-pointer inner loop
 * - Space: O(1) - only using constant extra space
 * - This is optimal - no algorithm can do better than O(n³) for 4Sum
 * 
 * INTERVIEW TALKING POINTS:
 * 1. "I sort first to enable two pointers and handle duplicates naturally"
 * 2. "The duplicate skipping is critical - wrong conditions cause bugs"  
 * 3. "Two pointers give us O(n) inner loop instead of O(n²) brute force"
 * 4. "This approach scales to k-Sum problems recursively"
 */