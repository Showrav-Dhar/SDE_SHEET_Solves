// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> nums = {3,3};
//     int target = 6;

//     // return the indices;

//     // Brute force

//     vector<int> ans;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             if (nums[i] + nums[j] == target)
//             {
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 break;
//             }
//         }
//         if (!ans.empty())
//         {
//             break;
//         }
//     }

//     for (auto it : ans)
//     {
//         cout << it << " ";
//     }

//     cout << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }


// better 

#include <bits/stdc++.h>
using namespace std;

/**
 * 
 * APPROACH: Hash Map (One Pass)
 * - For each element, check if (target - current_element) exists in map
 * - If exists: found our pair, return indices
 * - If not: store current element and its index in map
 * 
 * Time Complexity: O(n) - single pass through array
 * Space Complexity: O(n) - hash map storage in worst case
 */

vector<int> twoSum(vector<int>& nums, int target) 
{
    // Hash Map: value -> index mapping
    // Using unordered_map for O(1) average lookup (map is O(log n))
    unordered_map<int, int> hashDB;
    
    // Single pass through the array
    for (int i = 0; i < nums.size(); i++) 
    {
        int complement = target - nums[i];  // What we need to find
        
        // CHECK: Does complement exist in our hash map?
        if (hashDB.find(complement) != hashDB.end()) 
        {
            // FOUND: Return indices [previous_index, current_index]
            return {hashDB[complement], i};
        }
        
        // STORE: Add current element to hash map for future lookups
        hashDB[nums[i]] = i;
    }
    
    // This should never happen given problem constraints
    return {-1, -1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // TEST CASES
    vector<int> nums = {3, -1, -2, -3, -4, -6, 3};
    int target = -10;
    
    // Expected: indices where nums[i] + nums[j] = -10
    // nums[4] + nums[5] = -4 + (-6) = -10, so answer: [4, 5]
    
    vector<int> result = twoSum(nums, target);
    
    // OUTPUT FORMAT: Standard LeetCode expects vector return
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    cout << "Values: " << nums[result[0]] << " + " << nums[result[1]] 
         << " = " << (nums[result[0]] + nums[result[1]]) << endl;

    cerr << "Time elapsed: " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << endl;
    
    return 0;
}

/**
 * 
 * EDGE CASES TO CONSIDER:
 * - Duplicate values: [3,3], target=6 → both elements are same value
 * - Negative numbers: [-1,-2,-3,-4,-5], target=-8
 * - Zero in array: [0,4,3,0], target=0 → two zeros
 * 
 * INTERVIEW VARIATIONS:
 * - Two Sum II: Sorted array (use two pointers)
 * - Three Sum: Find triplets that sum to target
 * - Two Sum closest to target
 * - Two Sum - count pairs instead of returning indices
 * 
 * OPTIMIZATION NOTES:
 * - Used unordered_map instead of map for O(1) vs O(log n) lookup
 * - Single pass is optimal - can't do better than O(n)
 * - Early return when solution found (no need to continue)
 */

// optimal -  Two pointer approach, but as we use sorting the indices gets distorted
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {3, 2, 4};
    int target = 6;

    sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        int sum = nums[left] + nums[right];

        if (sum > target)
        {
            right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else if (sum == target)
        {
            break;
        }
    }

    cout << left << " " << right << endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}