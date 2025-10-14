// #include <bits/stdc++.h>
// using namespace std;

// vector<int> majorityElement(vector<int> v)
// {
//     int n = v.size(); // size of the array
//     vector<int> ls;   // list of answers

//     for (int i = 0; i < n; i++)
//     {
//         // selected element is v[i]:
//         //  Checking if v[i] is not already
//         //  a part of the answer:
//         if (ls.size() == 0 || ls[0] != v[i])
//         {
//             int cnt = 0;
//             for (int j = 0; j < n; j++)
//             {
//                 // counting the frequency of v[i]
//                 if (v[j] == v[i])
//                 {
//                     cnt++;
//                 }
//             }

//             // check if frquency is greater than n/3:
//             if (cnt > (n / 3))
//                 ls.push_back(v[i]);
//         }

//         if (ls.size() == 2)
//             break;
//     }

//     return ls;
// }

// int main()
// {
//     vector<int> arr = {11, 33, 33, 11, 33, 11};
//     vector<int> ans = majorityElement(arr);
//     cout << "The majority elements are: ";
//     for (auto it : ans)
//         cout << it << " ";
//     cout << "\n";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll arr[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     // better;

//     vector<int> arr = {11, 33, 33, 11, 33, 11};
//     int n = arr.size();

//     map<int, int> freq;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         freq[arr[i]]++;
//     }

//     vector<int> ans;

//     for (auto it : freq)
//     {
//         if (it.second >= floor(n / 3))
//         {
//             ans.push_back(it.first);
//         }
//     }

//     for (auto it : ans)
//     {
//         cout << it << " ";
//     }
//     cout << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// optimal -  Extended Boyer Moore's voting algo

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll arr[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {11, 33, 33, 11, 33, 11};
    // there will me at most 2 items with n/3 occurance
    int n = arr.size();

    int count1 = 0;
    int count2 = 0;

    int element1 = INT_MIN;
    int element2 = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 and element2 != arr[i])
        {
            count1++;
            element1 = arr[i];
        }
        else if (count2 == 0 and element1 != arr[i])
        {
            count2++;
            element2 = arr[i];
        }
        else if (arr[i] == element1)
        {
            count1++;
        }
        else if (arr[i] == element2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element1)
        {
            cnt1++;
        }
        else if (arr[i] == element2)
        {
            cnt2++;
        }
    }

    vector<int> ans;

    if (cnt1 > floor((float)n / 3))
    {
        ans.push_back(element1);
    }

    if (cnt2 > floor((float)n / 3))
    {
        ans.push_back(element2);
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}