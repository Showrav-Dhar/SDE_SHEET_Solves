#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ara = {10,10,10};

    int buying_price = ara[0]; // first i have to buy
    int selling_price = 0;
    int profit = 0;
    int temp_profit = 0;

    for (int i = 1; i < ara.size(); i++)
    {
        int current_price = ara[i];
        if (current_price < buying_price)
        {
            buying_price = current_price;
        }
        else
        {
            selling_price = current_price;
            temp_profit = selling_price - buying_price;
        }

        // cout << temp_profit << endl;
        profit = max(profit, temp_profit);
    }

    cout << profit << endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}