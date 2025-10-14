// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     double x, n;
//     x = 2, n = 3;

//     // if n is negative

//     double ans = 1;
//     for (int i = 1; i <= abs(n); i++)
//     {
//         ans = ans * x;
//     }

//     if (n < 0)
//     {
//         cout << (1 / ans) << endl;
//     }
//     cout << ans << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// optimal - Binary exponentiation

#include <bits/stdc++.h>
using namespace std;

double sd_pow(double x, int n)
{
    double ans = 1.0;

    long long nn = abs((long long)n); // made  the power positive

    while (nn)
    {
        if (nn % 2 == 1)
        { // if power is odd
            // When nn is odd:
            // Multiply current ans by x
            // Subtract 1 from nn (making it even)
            ans = ans * x;
            nn = nn - 1;
        }
        else
        { // if power is even
            // When nn is even:
            // Square x (x becomes x²)
            // Halve nn
            x = x * x;
            nn = nn / 2;
        }
    }

    if (n < 0)
    {
        ans = 1.0 / ans;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x, n;
    x = 2, n = 10;

    cout << sd_pow(x, n) << endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}