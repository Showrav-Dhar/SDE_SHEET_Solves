// #include <bits/stdc++.h>
// using namespace std;

// /**
//  * Helper function to check if a specific number exists in the array
//  * This performs a linear search through the entire array
//  * Time Complexity: O(n) for each call
//  * @param ara: reference to the input vector
//  * @param x: the number we're searching for
//  * @return: true if x is found in the array, false otherwise
//  */
// bool linear_search(vector<int> &ara, int x)
// {
//     bool fl = false;

//     // Iterate through entire array to find x
//     for (int i = 0; i < ara.size(); i++)
//     {
//         if (ara[i] == x)
//         {
//             fl = true;
//             break; // Found it, no need to continue
//         }
//     }
//     return fl;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> nums = {0, 1, 2, 3, 4, 10};

//     int ans = 1;    // Final answer - longest consecutive sequence length
//     int cnt = 1;    // Current sequence length being counted

//     // Main logic: For each number in the array, try to build a consecutive sequence
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int x = nums[i] + 1;  // Start looking for the next consecutive number
//         cnt = 1;              // Reset counter for current sequence (starts with current number)

//         // Keep extending the sequence as long as consecutive numbers exist
//         while (linear_search(nums, x) == true)
//         {
//             x = x + 1;  // Look for the next number in sequence
//             cnt++;      // Increment the length of current sequence
//         }

//         // Update the maximum sequence length found so far
//         ans = max(ans, cnt);
//     }

//     // This line is redundant - we already update ans inside the loop
//     ans = max(ans, cnt);

//     cout << ans << endl;

//     // Performance measurement (useful for optimization comparison)
//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// /**
//  * ALGORITHM ANALYSIS:
//  *
//  * Time Complexity: O(n³) - VERY INEFFICIENT!
//  * - Outer loop runs n times
//  * - For each element, we might search for up to n consecutive numbers
//  * - Each search takes O(n) time due to linear_search
//  * - Worst case: O(n) × O(n) × O(n) = O(n³)
//  *
//  * Space Complexity: O(1) - only using a few variables
//  *
//  * Example walkthrough with {0,1,2,3,4,10}:
//  * i=0, nums[0]=0: Look for 1,2,3,4,5 → sequence length = 5
//  * i=1, nums[1]=1: Look for 2,3,4,5 → sequence length = 4
//  * i=2, nums[2]=2: Look for 3,4,5 → sequence length = 3
//  * i=3, nums[3]=3: Look for 4,5 → sequence length = 2
//  * i=4, nums[4]=4: Look for 5 → sequence length = 1
//  * i=5, nums[5]=10: Look for 11 → sequence length = 1
//  *
//  * Maximum = 5, which is correct!
//  *
//  * ISSUES WITH THIS APPROACH:
//  * 1. Redundant work - we're finding the same sequence multiple times
//  * 2. Linear search is expensive - we do it repeatedly
//  * 3. No handling of duplicates (though problem assumes unique elements)
//  */

// Better -

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     // Test cases with duplicates to verify duplicate handling
//     // vector<int> nums = {0, 0, 1, 1, 2, 3, 4, 5, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
//     vector<int> nums = {0,0,1,1,2,2,3,3,4,4,5,5};

//     /**
//      * KEY OPTIMIZATION: Sort the array first
//      * This allows us to process consecutive sequences in a single pass
//      * Time: O(n log n), Space: O(1) if we modify input, O(n) if we create copy
//      */
//     sort(nums.begin(), nums.end());

//     int ct = 1;     // Current consecutive sequence length
//     int ans = 1;    // Maximum consecutive sequence length found

//     /**
//      * Single pass through sorted array
//      * Compare each element with the previous one to determine:
//      * 1. Continuation of sequence (diff = 1)
//      * 2. Duplicate element (diff = 0)
//      * 3. Break in sequence (diff > 1)
//      */
//     for (int i = 1; i < nums.size(); i++)
//     {
//         // Case 1: Next consecutive number found
//         if (nums[i] - nums[i - 1] == 1)
//         {
//             ct++;  // Extend current sequence
//         }
//         // Case 2: Duplicate number - skip it
//         else if (nums[i] - nums[i - 1] == 0)
//         {
//             continue;  // Don't reset counter, just ignore duplicate
//         }
//         // Case 3: Gap in sequence (difference > 1)
//         else
//         {
//             ans = max(ct, ans);  // Update maximum before starting new sequence
//             ct = 1;              // Reset counter for new sequence
//         }
//     }

//     /**
//      * IMPORTANT: Final update needed!
//      * The loop might end while we're still in a valid sequence,
//      * so we need to check one last time if the current sequence is the longest
//      */
//     ans = max(ct, ans);

//     cout << ans << endl;
//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// /**
//  * ALGORITHM ANALYSIS:
//  *
//  * Time Complexity: O(n log n) - dominated by sorting
//  * - Sorting: O(n log n)
//  * - Single pass: O(n)
//  * - Overall: O(n log n)
//  *
//  * Space Complexity: O(1) - only using a few variables (assuming in-place sort)
//  *
//  * Example walkthrough with {0,0,1,1,2,2,3,3,4,4,5,5}:
//  * After sorting: [0,0,1,1,2,2,3,3,4,4,5,5]
//  *
//  * i=1: nums[1]=0, nums[0]=0 → diff=0 (duplicate) → continue, ct=1
//  * i=2: nums[2]=1, nums[1]=0 → diff=1 (consecutive) → ct=2
//  * i=3: nums[3]=1, nums[2]=1 → diff=0 (duplicate) → continue, ct=2
//  * i=4: nums[4]=2, nums[3]=1 → diff=1 (consecutive) → ct=3
//  * i=5: nums[5]=2, nums[4]=2 → diff=0 (duplicate) → continue, ct=3
//  * ... pattern continues ...
//  * Final sequence: 0,1,2,3,4,5 → length = 6
//  *
//  * ADVANTAGES over brute force:
//  * ✅ Much better time complexity: O(n log n) vs O(n³)
//  * ✅ Elegant single-pass logic after sorting
//  * ✅ Handles duplicates correctly
//  * ✅ Easy to understand and debug
//  *
//  * COMPARISON to optimal O(n) HashSet solution:
//  * ✅ Simpler to implement and understand
//  * ✅ No extra space for hash set
//  * ❌ Slightly slower due to sorting overhead
//  * ❌ Modifies input array (if that matters)
//  *
//  * This is an excellent solution for interviews - clean, efficient, and easy to explain!
//  */

// Optimal

// How to identify if a number can be the starting number for a sequence:

// First, we will put all the array elements into the set data structure.
// If a number, num, is a starting number, ideally, num-1 should not exist. So, for every element, x, in the set, we will check if x-1 exists inside the set. :
// If x-1 exists: This means x cannot be a starting number and we will move on to the next element in the set.
// If x-1 does not exist: This means x is a starting number of a sequence. So, for number, x, we will start finding the consecutive elements.
// How to search for consecutive elements for a number, x:

// Instead of using linear search, we will use the set data structure itself to search for the elements x+1, x+2, x+3, and so on.
// Thus, using this method we can narrow down the search and optimize the approach.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};

    /**
     * STEP 1: Build HashSet for O(1) lookup
     * unordered_set automatically handles duplicates - they're ignored
     * Time: O(n), Space: O(n)
     */
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);  // Duplicates automatically ignored
    }

    int cnt = 1;    // Current sequence length
    int ans = 1;    // Maximum sequence length found

    /**
     * STEP 2: The KEY INSIGHT - Smart Sequence Detection
     * For each number in the set, we only start counting a sequence
     * if this number is the START of a potential sequence.
     * 
     * How do we know it's a start? If (current_number - 1) doesn't exist!
     * This prevents redundant work and ensures O(n) complexity.
     */
    for (auto it : st)
    {
        /**
         * CRITICAL CHECK: Is this the beginning of a sequence?
         * If (it-1) exists in set, then 'it' is NOT the start of the sequence
         * We'll process this sequence when we encounter its actual start
         */
        if (st.find(it - 1) == st.end())
        {
            cnt = 1;     // Reset counter - starting new sequence
            int x = it;  // Current number we're checking
            
            /**
             * STEP 3: Count consecutive numbers forward
             * Keep extending sequence as long as next consecutive number exists
             * This inner loop runs at most O(n) times TOTAL across all iterations
             */
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;      // Move to next consecutive number
                cnt = cnt + 1;  // Increment sequence length
            }
            
            // Update maximum sequence length found
            ans = max(cnt, ans);
        }
        // If (it-1) exists, we skip this number - it's not a sequence start
    }
    
    // This line is actually redundant since we update ans inside the loop
    ans = max(cnt, ans);

    cout << ans << endl;
}

/**
 * ALGORITHM ANALYSIS:
 * 
 * Time Complexity: O(n) - OPTIMAL!
 * - Building set: O(n)
 * - Main loop: appears to be O(n²) but it's actually O(n)!
 *   - Outer loop: O(n) iterations
 *   - Inner while loop: Each number is visited at most twice
 *     (once when we check if it's a start, once when we extend from its predecessor)
 *   - Total: O(n) + O(n) = O(n)
 * 
 * Space Complexity: O(n) for the unordered_set
 * 
 * Example walkthrough with {0,1,2,3,4,5,10,11,12,13,14,15,16,17,18,19,20}:
 * 
 * Process 0: (0-1)=-1 not in set → START of sequence
 *   - Count: 0,1,2,3,4,5 → length = 6
 * Process 1: (1-1)=0 exists in set → SKIP (not a start)
 * Process 2: (2-1)=1 exists in set → SKIP
 * ... (skip 3,4,5 for same reason)
 * Process 10: (10-1)=9 not in set → START of sequence
 *   - Count: 10,11,12,13,14,15,16,17,18,19,20 → length = 11
 * Process 11,12,13... → SKIP all (not starts)
 * 
 * Maximum = 11 (sequence from 10 to 20)
 * 
 * WHY THIS IS BRILLIANT:
 * ✅ Each number is processed at most twice (once as potential start, once as extension)
 * ✅ No redundant sequence counting
 * ✅ Handles duplicates automatically via set
 * ✅ True O(n) time complexity
 * ✅ Clean, elegant logic
 * 
 * This is the gold standard solution for this problem!
 */