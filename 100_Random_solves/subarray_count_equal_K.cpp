#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ara = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int target = 0;

    long long int pref_sum = 0;
    map<long long int, int> hash_map;

    int ct = 0;

    for (int i = 0; i < ara.size(); i++)
    {
        pref_sum += ara[i];

        if (pref_sum == target)
        {
            ct++;
        }

        int rem_sum = pref_sum - target;

        if (hash_map.find(rem_sum) != hash_map.end())
        {
            ct += hash_map[rem_sum];
        }

        hash_map[pref_sum]++;
    }

    cout << ct << endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}