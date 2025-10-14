// // majority element

// // Bruteforce
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> ara = {2, 2, 1, 1, 1, 2, 2};
//     int n = ara.size();
//     int ans = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int ct = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (ara[i] == ara[j])
//             {
//                 ct++;
//             }
//         }
//         if (ct >= (n / 2))
//         {
//             ans = ara[i];
//             break;
//         }
//     }

//     cout << ans << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// better -

// majority element

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> ara = {2, 2, 1, 1, 1, 2, 2};
//     int n = ara.size();

//     map<int, int> freq;
//     for (int i = 0; i < n; i++)
//     {
//         freq[ara[i]]++;
//     }
//     int ans = 0;

//     for (auto it : freq)
//     {
//         if (it.second >= (n / 2))
//         {
//             ans = it.first;
//         }
//     }

//     cout << ans << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// optimal

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ara = {2, 2, 1, 1, 1, 2, 2};
    int n = ara.size();

    int count = 0;
    int element = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count++;
            element = ara[i];
        }
        else if (element == ara[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (element == ara[i])
        {
            count2++;
        }
    }

    int ans = -1;
    if (count2 >= (double)n / 2)
    {
        ans = element;
    }

    cout << ans << endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}