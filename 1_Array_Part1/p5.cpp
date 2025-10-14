// Sort Colors

// brute force

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     // without STL, just write any efficient sorting algo

//     vector<int> ara = {3, 2, 1, 4};
//     int n = ara.size();

//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (ara[j] > ara[j + 1])
//             {
//                 swap(ara[j], ara[j + 1]);
//             }
//         }
//     }

//     for (auto it : ara)
//     {
//         cout << it << " ";
//     }

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// Better -

// as we already know that the array
// will contain only 0,1 and 2
// so just take 3 variables and stroe how many times they are oresent and just print them

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> ara = {1, 1, 1, 0, 0, 0, 1, 2, 2, 2, 2};

//     int one = 0, two = 0, zero = 0;

//     for (int i = 0; i < ara.size(); i++)
//     {
//         if (ara[i] == 0)
//         {
//             zero++;
//         }
//         else if (ara[i] == 1)
//         {
//             one++;
//         }
//         else if (ara[i] == 2)
//         {
//             two++;
//         }
//     }

//     while (zero--)
//     {
//         cout << 0 << " ";
//     }

//     while (one--)
//     {
//         cout << 1 << " ";
//     }

//     while (two--)
//     {
//         cout << 2 << " ";
//     }

//     cout << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// Optimal - Dutch National Flag algo

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ara = {2, 0, 2, 1, 1, 0};

    int low = 0;
    int mid = 0;
    int high = ara.size() - 1;

    // we have unsorted section from mid till high
    // so the while loop will be also mid<=high

    while (mid <= high)
    {

        if (ara[mid] == 0)
        {
            swap(ara[low], ara[mid]); // 0 to low - 1 contains zero
            low++;
            mid++;
        }
        else if (ara[mid] == 1)
        {
            mid++; // low to mid contains 1
        }
        else if (ara[mid] == 2)
        {
            swap(ara[mid], ara[high]);
            high--; // high + 1 to n - 1 contains 2
        }
    }

    for (auto it : ara)
    {
        cout << it << " ";
    }

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}