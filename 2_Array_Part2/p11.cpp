// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     >>>>>>>         BRUTE FORCE          <<<<<<<<        //

//     vector<int> ara = {4, 3, 6, 2, 1, 1};

//     int n = ara.size();

//     sort(ara.begin(), ara.end()); // n log n

//     int ct = 1;
//     int duplicate = 0;
//     for (int i = 1; i < n; i++) // n
//     {
//         if (ara[i - 1] == ara[i])
//         {
//             ct++;
//             if (ct == 2)
//             {
//                 duplicate = ara[i];
//                 break;
//             }
//         }
//     }

//     // xor
//     int items = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         items = items ^ i;
//     }

//     items = items ^ duplicate;

//     for (int i = 0; i < n; i++)
//     {
//         items = items ^ ara[i];
//     }

//     int missing = items;

//     cout<<duplicate<<" "<<missing<<endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//      >>>>>>>         BETTER         <<<<<<<<        //

//     vector<int> ara = {4, 3, 6, 2, 1, 1};

//     long long long long int n = ara.size();

//     long long int original_sum = (n * (n + 1)) / 2;
//     long long int current_sum = 0;

//     map<int, int> freq;

//     int duplicate = -1;

//     for (int i = 0; i < n; i++)
//     {
//         freq[ara[i]]++;
//         if (freq[ara[i]] >= 2 and duplicate == -1)
//         {
//             duplicate = ara[i];
//         }
//         current_sum = current_sum + ara[i];
//     }

//     current_sum = current_sum - duplicate;

//     long long int missing_value = original_sum - current_sum;

//     cout << duplicate << " " << missing_value << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // >>>>>>>         OPTIMAL         <<<<<<<<        //

    vector<int> ara = {4, 3, 6, 2, 1, 1};

    // take long long int
    long long int n = ara.size();

    long long int sum_expected = (n * (n + 1)) / 2;                       // Sum of first n numbers
    long long int sum_squares_expected = (n * (n + 1) * (2 * n + 1)) / 6; // Sum of squares of first n numbers

    long long int sum_actual = 0;
    long long int sum_squares_actual = 0;

    for (int i = 0; i < n; i++)
    {
        sum_actual += 1LL * ara[i];
        sum_squares_actual += 1LL * (ara[i] * ara[i]);
    }

    long long int val1 = sum_actual - sum_expected; // x - y

    long long int val2 = sum_squares_actual - sum_squares_expected; // x^2 - y^2 = (x - y)(x + y)

    val2 = val2 / val1; // x + y

    long long int x = (val1 + val2) / 2; // repeating
    long long int y = val2 - x;          // missing

    cout << x << " " << y << endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}
