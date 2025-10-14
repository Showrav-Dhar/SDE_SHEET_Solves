// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // brute
//     vector<int> ara = {7, 2, 1, 10, 6, 20};
//     int ans = INT_MIN;
//     for (int i = 0; i < ara.size(); i++) // buy
//     {
//         int mx = INT_MIN;
//         for (int j = i + 1; j < ara.size(); j++) // sell
//         {
//             int dif = ara[j] - ara[i]; // sell - buy
//             mx = max(dif, mx);
//         }
//         ans = max(mx, ans);
//     }
//     cout << ans << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// optimal

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ara = {7, 1, 5, 3, 6, 4};

    int minimum_buying_price = INT_MAX;
    int maximum_profit = 0;

    for (int i = 0; i < ara.size(); i++)
    {
        minimum_buying_price = min(minimum_buying_price,ara[i]);
        maximum_profit = max(maximum_profit,ara[i]-minimum_buying_price);
    }

    cout<<maximum_profit<<endl;
    


    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}
