#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ara = {1, 2, 0, -3, 0, 0, 3, -3};

    int n = ara.size();

    int len = 0;
    int max_len = 0;

    long long int pref_sum = 0;
    map<long long int, int> hash_map;

    for (int i = 0; i < n; i++)
    {

        pref_sum = pref_sum + ara[i];

        if (pref_sum == 0)
        { // 0 is the target sum
            max_len = max(max_len, i + 1);
        }

        // rem_sum = pref_sum - k;
        // rem_sum = pref_sum - 0;

        if (hash_map.find(pref_sum) != hash_map.end())
        {

            len = i - hash_map[pref_sum];
            max_len = max(max_len, len);
        }

        if (hash_map.find(pref_sum) == hash_map.end())
        {
            hash_map[pref_sum] = i;
        }
    }

    cout<<max_len<<endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}