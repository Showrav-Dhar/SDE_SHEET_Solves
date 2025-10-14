// // #include <bits/stdc++.h>
// // using namespace std;
// // typedef long long int ll;
// // const int mx = 1e7 + 123;
// // ll ara[mx];
// // int main()
// // {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);
// //     // BRUTEFORCE - TIME - O(nlogn)xO(N), nlogn for sorting
// //     vector<int> nums = {3, 1, 3, 4, 2};

// //     sort(nums.begin(), nums.end());
// //     // sorted the array so that the similar item
// //     // stays beside one another

// //     int counter = 1; // every item is present at least one time
// //     int duplicate = 0;
// //     for (int i = 1; i < nums.size(); i++)
// //     {
// //         if (nums[i - 1] == nums[i])
// //         {
// //             counter++;
// //         }
// //         if (counter == 2)
// //         {
// //             duplicate = nums[i];
// //             break;
// //         }
// //     }

// //     cout << duplicate << endl;

// //     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// // }

// // better

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> nums = {3, 1, 3, 4, 2};

//     map<int, int> freq;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         freq[nums[i]]++;
//     }

//     int ans = 0;
//     for (auto it : freq)
//     {
//         if (it.second >= 2)
//         {
//             ans = it.first;
//             break;
//         }
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

    vector<int> nums = {3, 1, 3, 4, 2};
    // slow and fast pointer
    // step 1

    // initially both pointer points at first item
    int slow_pointer = nums[0];
    int fast_pointer = nums[0];

    // searching the first collide point
    do
    {
        slow_pointer = nums[slow_pointer];       // moves 1 step at a time
        fast_pointer = nums[nums[fast_pointer]]; // moves 2 step at a time

    } while (slow_pointer != fast_pointer);

    // step 2
    // searching the second collide point, to find the duplicate item

    // placing the fast pointer to the first item
    fast_pointer = nums[0];

    // this time slow and fast pointer will move 1 step at a time

    while (slow_pointer != fast_pointer)
    {
        slow_pointer = nums[slow_pointer];
        fast_pointer = nums[fast_pointer];
    }

    cout << slow_pointer << endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}