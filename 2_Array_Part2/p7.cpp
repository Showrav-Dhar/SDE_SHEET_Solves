// // Rotate Image -

// // brute force -
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<vector<int>> ara = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int r = ara.size();
//     int c = ara[0].size();

//     vector < vector<int> > temp_mat (r, vector<int>(c, 0));
//     int i1 = 0, j1 = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 3 - 1; j >= 0; j--)
//         {
//             // cout << ara[j][i] << " ";
//             temp_mat[i1][j1] = ara[j][i];
//             j1++;
//         }
//         i1++;
//         j1 = 0;
//         cout << endl;
//     }

//     for (int i1 = 0; i1 < 3; i1++)
//     {
//         for (int j1 = 0; j1 < 3; j1++)
//         {
//             cout << temp_mat[i1][j1] << " ";
//         }
//         cout << endl;
//     }

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// Optimal - transpose and reverse each row - 90 degree clock wise


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> ara = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int r = ara.size();
    int c = ara[0].size();

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << ara[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    // matrix transpose

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(ara[i][j], ara[j][i]);
        }
    }

    for (int i = 0; i < r; i++)
    {
        reverse(ara[i].begin(), ara[i].end());
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << ara[i][j] << " ";
        }
        cout << endl;
    }

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}