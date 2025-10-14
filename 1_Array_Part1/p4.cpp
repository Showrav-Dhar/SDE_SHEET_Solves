// // -- Maximum Subarray Sum -- //

// // Brueforce // O(N cube)

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> ara = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

//     int max_sum = INT_MIN;

//     for (int i = 0; i < ara.size(); i++)
//     {

//         for (int j = 0; j < ara.size(); j++)
//         {
//             int sum = 0;
//             for (int k = i; k <= j; k++)
//             {
//                 sum += ara[k];
//             }
//             max_sum = max(max_sum, sum);
//         }
//     }

//     cout << max_sum << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// optimal - reduce the third loop

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> ara = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

//     int max_sum = INT_MIN;

//     for (int i = 0; i < ara.size(); i++)
//     {
//         int sum = 0;
//         for (int j = i; j < ara.size(); j++)
//         {
//             // cout<<ara[j]<<" ";
//             sum += ara[j];
//             // cout << sum << " ";
//             max_sum = max(max_sum, sum); // checking the sum every time works like the third loop
//         }
//         // cout << endl;
//     }

//     cout << max_sum << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
//}

// Optimal -- kadane's algorithm

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> ara = {-2};

//     int max_sum = INT_MIN;
//     int sum = 0;
//     for (int i = 0; i < ara.size(); i++)
//     {
//         sum += ara[i];
//         max_sum = max(max_sum, sum);
//         if (sum < 0)
//         {
//             sum = 0;
//         }
//         // cout<<sum<<" ";
//     }

//     cout << max_sum << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// FOLLOW UP QUESTION

// PRINT THE ARRAY WITH MAXIMUM SUBARRAY SUM

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ara = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int maximum_sum = INT_MIN;
    int current_sum = 0;

    int start = 0;

    int ans_start = -1, ans_end = -1;

    for (int i = 0; i < ara.size(); i++)
    {
        if (current_sum == 0)
        {
            start = i;
        }
        current_sum = current_sum + ara[i];
        // maximum_sum = max(maximum_sum, current_sum);

        if (current_sum > maximum_sum)
        {
            maximum_sum = current_sum;
            ans_start = start;
            ans_end = i;
        }
        if (current_sum < 0)
        {
            current_sum = 0;
        }
    }

    cout << " Maximum Subarray Sum = " << maximum_sum << endl;
    cout << "Resulting Array\n";
    for (int i = ans_start; i <= ans_end; i++)
    {
        cout << ara[i] << " ";
    }
    cout << endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}