// // Problem Statement: This problem has 3 variations. They are stated below:

// // Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

// // Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

// // Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     // variation 1
//     int n = 5, r = 5, c = 3;

//     vector<vector<int>> ans;

//     ans.push_back({1});       // 1 // ans index 0
//     ans.push_back({1, 1});    // 2 // 1
//     ans.push_back({1, 2, 1}); // 3 // 2
//     for (int i = 3; i < n; i++)
//     {
//         vector<int> ara;
//         ara.push_back(1);
//         for (int j = 1; j < ans[i - 1].size(); j++)
//         {
//             int a = ans[i - 1][j] + ans[i - 1][j - 1];
//             ara.push_back(a);
//         }
//         ara.push_back(1);
//         ans.push_back(ara);
//         ara.clear();
//     }

//     cout << "variation 1 answer" << endl;
//     cout << ans[r - 1][c - 1] << endl;

//     cout << "variation 2 answer" << endl;
//     for (auto it : ans[r - 1])
//     {
//         cout << it << " ";
//     }
//     cout << endl;

//     cout << "variation 3 answer" << endl;
//     for (auto it : ans)
//     {
//         for (auto p : it)
//         {
//             cout << p << " ";
//         }
//         cout << endl;
//     }

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }