// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     // BRUTEFORCE Approach

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<vector<int>> ara = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};

//     // first step - Make the intervals close to search faster
//     sort(ara.begin(), ara.end());

//     // second step -
//     // stand at one point look right side to group the interval
//     // condition to group is to check if start[j][0](start) is less than or equal to end[i] else break
//     int n = ara.size();

//     vector<vector<int>> ans; // to store the answers interval

//     for (int i = 0; i < n; i++)
//     {
//         int start = ara[i][0];
//         int end = ara[i][1];

//         if (!ans.empty() and end <= ans.back()[1])
//         {
//             continue;
//             // if there is already an interval pair in the answer array and
//             // if current interval end <= previous interval's end point from the answer array
//             // then no need to consider the current interval as a standing point
//         }

//         for (int j = i + 1; j < n; j++)
//         {
//             if (ara[j][0] <= end)
//             {
//                 end = max(end, ara[j][1]);
//                 // expanding the interval end point
//             }
//             else
//             {
//                 break;
//             }
//         }

//         ans.push_back({start, end});
//     }

//     for (auto it : ans)
//     {
//         cout << it[0] << " " << it[1] << endl;
//     }

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// OPTIMAL

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> ara = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};

    // step 1 - sort
    sort(ara.begin(),ara.end());

    int n = ara.size();

    vector<vector<int>> ans;
    // step 2 - begin with first interval, 
    // check the end value of each interval and expand the interval if its overlapping
    // else add the interval to the answer array

    ans.push_back({ara[0][0], ara[0][1]}); // taking the first interval as default

    for (int i = 1; i < n; i++)
    {
        int start = ara[i][0];
        int end = ara[i][1];

        if (end <= ans.back()[1]) // if current end is less than already stored interval than no need to check
        {
            continue;
        }
        else if (start <= ans.back()[1])
        {
            // if current end is overlapping, expand the end
            ans.back()[1] = max(ans.back()[1], end);
        }
        else
        {
            // if above condition fails, start a new interval
            ans.push_back({start, end});
        }
    }

    for (auto it : ans)
    {
        cout << it[0] << " " << it[1] << endl;
    }

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}