/// -- Facebook Question -- /// 



// brute force

// all possible permutaion using recursion -

// as it is very large time complexity we will avoid it
// O(N!)*N

// better

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> ara = {1, 2, 3};

//     next_permutation(ara.begin(), ara.end());

//     for (auto it : ara)
//     {
//         cout << it << " ";
//     }

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// optimal--

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ara = {2, 1, 5, 4, 3, 0, 0};

    int sz = ara.size();

    // step 1 - Find the drop index
    int drop_index = -1;
    for (int i = sz - 2; i >= 0; i--)
    {
        if (ara[i] < ara[i + 1])
        {
            drop_index = i;
            break;
        }
    }

    if (drop_index == -1)
    {
        // array sorted in descending order, which is
        // the last lexicographical permutation available
        reverse(ara.begin(), ara.end());

        for (auto it : ara)
        {
            cout << it << " ";
        }
        cout << endl;
        return 0;
    }

    // step 2 - find the closest largest of ara[i]
    // and swap with ara[i]

    for (int i = sz - 1; i >= 0; i--)
    {
        if (ara[i] > ara[drop_index])
        {
            swap(ara[i], ara[drop_index]);
            break;
        }
    }

    // step 3 - sort the array from drop_index + 1 to last index
    sort(ara.begin() + drop_index + 1, ara.end());

    for (auto it : ara)
    {
        cout << it << " ";
    }
    cout << endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}