// optimal - 


// Solution is inspired from - longest subarray with K(problem 21) and count the number of subarray equal K

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ara = {3, 3, 3, 3};

    int k = 3;

    int ct = 0;

    int pref_xor = 0;
    map<int, int> hash_map;

    for (int i = 0; i < ara.size(); i++)
    {
        pref_xor = pref_xor ^ ara[i];

        if (pref_xor == k)
        {
            ct++;
        }

        int rem_xor = pref_xor ^ k;

        if (hash_map.find(rem_xor) != hash_map.end())
        {
            ct += hash_map[rem_xor];
        }

        hash_map[pref_xor]++;
    }

    cout<<ct<<endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}
