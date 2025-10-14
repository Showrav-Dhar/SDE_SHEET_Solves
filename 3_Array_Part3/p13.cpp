// // //// Bruteforce -

// // #include <bits/stdc++.h>
// // using namespace std;
// // typedef long long int ll;
// // const int mx = 1e7 + 123;
// // ll ara[mx];
// // int main()
// // {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);

// //     vector<vector<int>> ara = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

// //     int target = 3;

// //     int row = ara.size();
// //     int col = ara[0].size();

// //     bool flag = 0;

// //     for (int i = 0; i < row; i++)
// //     {
// //         for (int j = 0; j < col; j++)
// //         {
// //             if(ara[i][j] == target){
// //                 flag = true;
// //                 break;
// //             }
// //         }

// //     }

// //     cout<<flag<<endl;

// //     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// // }

// // optimal

// //// Bruteforce -

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<vector<int>> ara = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

//     int target = 3;

//     int row = ara.size();
//     int col = ara[0].size();

//     bool flag = 0;

//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if(ara[i][j] == target){
//                 flag = true;
//                 break;
//             }
//         }

//     }

//     cout<<flag<<endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     // Better
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<vector<int>> ara = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

//     int target = 3;

//     int row = ara.size();
//     // int col = ara[0].size();

//     bool flag = 0;

//     for (int i = 0; i < row; i++)
//     {
//         flag = binary_search(ara[i].begin(), ara[i].end(), target);
//         if (flag == true)
//         {
//             break;
//         }
//     }

//     cout << flag << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// Better 2.

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<vector<int>> ara = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

//     int target = 3;

//     int row = ara.size();
//     int col = ara[0].size();

//     bool flag = 0;

//     for (int i = 0; i < row; i++)
//     {
//         if (ara[i][0] <= target and target <= ara[i][col - 1])
//         {
//             flag = binary_search(ara[i].begin(), ara[i].end(), target);
//         }
//     }

//     if (flag)
//     {
//         cout << "Target is Present" << endl;
//     }
//     else
//     {
//         cout << "Target is not present" << endl;
//     }

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// Optimal

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> ara = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    int target = 3;

    int row = ara.size();
    int col = ara[0].size();

    int low = 0;
    int high = (row * col) - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int r = mid / col;
        int c = mid % col;
        int item = ara[r][c];
        cout<<item<<endl;
        if (item == target)
        {
            cout << "Target is present\n";
            break;
        }

        if (item > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}