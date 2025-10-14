
// --   BRUTE FORCE -- //
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<vector<int>> matrix;
//     int row = 3, col = 3;
//     for (int i = 0; i < row; i++)
//     {
//         vector<int> ara;
//         for (int j = 0; j < col; j++)
//         {
//             int a;
//             cin >> a;
//             ara.push_back(a);
//         }
//         matrix.push_back(ara);
//     }

//     set<int> row_cleaner;
//     set<int> col_cleaner;

//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 row_cleaner.insert(i);
//                 col_cleaner.insert(j);
//             }
//         }
//     }

//     for (auto it : row_cleaner)
//     {
//         for (int i = 0; i < col; i++)
//         {
//             matrix[it][i] = 0;
//         }
//     }

//     for (auto it : col_cleaner)
//     {
//         for (int i = 0; i < row; i++)
//         {
//             matrix[i][it] = 0;
//         }
//     }

//     for (int i = 0; i < row; i++)
//     {

//         for (int j = 0; j < col; j++)
//         {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// --   BETTER -- //

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<vector<int>> matrix;
//     int row = 3, col = 3;
//     for (int i = 0; i < row; i++)
//     {
//         vector<int> ara;
//         for (int j = 0; j < col; j++)
//         {
//             int a;
//             cin >> a;
//             ara.push_back(a);
//         }
//         matrix.push_back(ara);
//     }

//     vector<int> row_pos(row,0);
//     vector<int> col_pos(col,0);

//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 row_pos[i] = 1;
//                 col_pos[j] = 1;
//             }
//         }
//     }

//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if(row_pos[i] == 1 || col_pos[j] == 1){
//                 matrix[i][j] = 0;
//             }
//         }
//     }

//     // space O(m+n)
//     // time O(2(m*n))

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// ---- optimal --- //

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> matrix = {{1,0,3}};
    int r = 1, c = 3;
    // for (int row = 0; row < r; row++)
    // {
    //     vector<int> ara;
    //     for (int col = 0; col < c; col++)
    //     {
    //         int a;
    //         cin >> a;
    //         ara.push_back(a);
    //     }
    //     matrix.push_back(ara);
    // }

    // step 1

    int col_checker = 1;

    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            if (matrix[row][col] == 0)
            {
                matrix[row][0] = 0; // marking each rows that have 0

                if (col != 0)
                {
                    matrix[0][col] = 0; // marking all col that have 0
                }
                else
                {
                    col_checker = 0; // first row has 0 originally
                }
            }
        }
    }

    // step 2 cleaning the whole matrix without 1st row and 1st col

    for (int row = 1; row < r; row++)
    {
        for (int col = 1; col < c; col++)
        {
            if (matrix[row][col] != 0) // <<<<<- imp check
            {
                // if a cell does not have zero,
                // checking its entire row and column
                if (matrix[row][0] == 0 or matrix[0][col] == 0)
                {
                    matrix[row][col] = 0;
                }
            }
        }
    }

    // step 3 cleaning 1st row and col
    if (matrix[0][0] == 0) // checking if first column has 0 originally
    {
        for (int col = 0; col < c; col++)
        {
            matrix[0][col] = 0;
        }
    }

    if (col_checker == 0) // checking if first row has 0 originally
    {
        for (int row = 0; row < r; row++)
        {
            matrix[row][0] = 0;
        }
    }

    // print

    for (int row = 0; row < r; row++)
    {

        for (int col = 0; col < c; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}