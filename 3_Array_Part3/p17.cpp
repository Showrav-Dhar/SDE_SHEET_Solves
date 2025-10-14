// #include <bits/stdc++.h>
// using namespace std;

// // Brute Force --
// int count_unique_paths(int i, int j, int row, int col)
// {
//     if (i == row - 1 and j == col - 1) // reached the final point
//     {
//         return 1;
//     }

//     if (i >= row or j >= col) // out of boundary
//     {
//         return 0;
//     }
//     else
//     {   // recurise = right (i,j+1) + down (i+1,j)
//         return count_unique_paths(i + 1, j, row, col) + count_unique_paths(i, j + 1, row, col);
//         // left recursion tree result + right recursion tree result
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int row = 3;
//     int col = 7;

//     int i = 0; // starting point
//     int j = 0; // starting point
//     int ans = count_unique_paths(i, j, row, col);

//     cout << ans << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;

/**
 * PROBLEM: Grid Unique Paths (LeetCode 62)
 * Find number of unique paths from top-left (0,0) to bottom-right (m-1,n-1)
 * Can only move RIGHT or DOWN
 *
 * APPROACH: Top-Down Dynamic Programming (Memoization)
 * Time Complexity: O(m*n) - each cell computed once
 * Space Complexity: O(m*n) - DP table + O(m+n) recursion stack
 */

// Top-Down DP with Memoization
// int count_unique_paths(int i, int j, int row, int col, vector<vector<int>> &dp)
// {
//     // BASE CASE 1: Reached destination (bottom-right corner)
//     if (i == row - 1 and j == col - 1)
//     {
//         return 1; // Found one valid path
//     }

//     // BASE CASE 2: Out of bounds (went beyond grid boundaries)
//     if (i >= row or j >= col)
//     {
//         return 0; // Invalid path
//     }

//     // MEMOIZATION: If already computed, return cached result
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }

//     // RECURRENCE RELATION: paths = paths_going_down + paths_going_right
//     // Store result in dp table before returning (memoization)
//     else
//     {
//         return dp[i][j] = count_unique_paths(i + 1, j, row, col, dp) + // Move DOWN
//                           count_unique_paths(i, j + 1, row, col, dp);  // Move RIGHT
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     // GRID DIMENSIONS
//     int row = 3; // m rows (0 to m-1)
//     int col = 7; // n columns (0 to n-1)

//     // STARTING POSITION
//     int i = 0; // start row
//     int j = 0; // start column

//     // INITIALIZE DP TABLE: -1 means not computed yet
//     vector<vector<int>> dp(row, vector<int>(col, -1));

//     // SOLVE
//     int ans = count_unique_paths(i, j, row, col, dp);

//     cout << ans << endl;

//     // PERFORMANCE TRACKING
//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;

//     return 0;
// }

/**
 * ALTERNATIVE APPROACHES TO CONSIDER:
 *
 * 1. BOTTOM-UP DP (Tabulation):
 *    - Fill dp table iteratively from bottom-right to top-left
 *    - Same time/space complexity, no recursion overhead
 *
 * 2. SPACE OPTIMIZED DP:
 *    - Only need previous row/column, reduce space to O(min(m,n))
 *
 * 3. MATHEMATICAL SOLUTION:
 *    - Total moves needed: (m-1) down + (n-1) right = (m+n-2) moves
 *    - Choose (m-1) positions for down moves: C(m+n-2, m-1)
 *    - Time: O(min(m,n)), Space: O(1)
 *
 * INTERVIEW FOLLOW-UPS:
 * - What if there are obstacles in the grid? (LeetCode 63)
 * - What if we want the actual paths, not just count?
 * - Can you optimize space further?
 */

// Combinatorics

#include <bits/stdc++.h>
using namespace std;
// https://www.geeksfrgeeks.org/dsa/program-calculate-value-ncr/
int count_unique_paths(int n, int r)
{
    // calculate nCr
    double ans = 1;

    for (int i = 1; i <= r; i++)
    {
        ans = ans * (n - r + i) / i;
    }

    return (int)ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row = 3;
    int col = 7;

    int ans = count_unique_paths(row + col - 2, row - 1);


    cout<<ans<<endl;


    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}
