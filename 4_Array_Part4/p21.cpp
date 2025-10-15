// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

// Brute force -

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> ara = {10, 5, 2, 7, 1, -10};
//     int target = 15;

//     int n = ara.size();

//     int len = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         sum = ara[i];
//         if (sum == target)
//         {
//             len = 1;
//         }
//         for (int j = i + 1; j < n; j++)
//         {
//             sum = sum + ara[j];
//             if (sum == target)
//             {
//                 len = max(len, j - i + 1);
//             }
//         }
//     }

//     cout << len << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// better - for array containing positive, negative and zero

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> ara = {10, 5, 2, 7, 1, -10};
//     int k = 15;

//     map<long long int, int> hash_map; // < current_pref_sem, current_index >
//     long long int pref_sum = 0;

//     int len = 0;
//     int max_len = 0;

//     for (int i = 0; i < ara.size(); i++)
//     {
//         pref_sum += ara[i]; // taking every item in the prefix sum

//         if (pref_sum == k) // checking if current sum is equal K
//         {
//             max_len = max(max_len, i + 1); // i + 1 , because of 0 based indexing
//         }

//         long long int remain_sum = pref_sum - k; // if there are any sub_array_sum = pref_sum - k,
//         // if there is it means that, the item in the current index, give us a subarray sum of k

//         if (hash_map.find(remain_sum) != hash_map.end())
//         { // now checking if the remain_sum is in the map

//             len = i - hash_map[remain_sum];
//             // calculating the length of the current subarray that is giving K, witht the current item as the last index
//             max_len = max(len, max_len);
//             // storing the max length
//         }

//         if (hash_map.find(pref_sum) == hash_map.end())
//         {// now storing the current sum, in the map, by checking if it does already exist in the map or not
//             // because of 0 and negative items.
//             hash_map[pref_sum] = i;
//         }
//     }

//     cout << max_len << endl;

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// optimal - only for if the array contains = positive and zero

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ara = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    int k = 6;

    int n = ara.size();

    int left = 0;
    int right = 0;
    int sum = ara[0];
    int max_len = 0;

    while (right < n)
    {
        while (left <= right and sum > k)
        {
            sum = sum - ara[left];
            left++;
        }

        if (sum == k)
        {
            max_len = max(max_len, right - left + 1);
        }

        right++;
        if (right < n)
        {
            sum += ara[right];
        }
    }

    cout << sum << endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}


// Subarray related problems - 

// https://leetcode.com/problems/contiguous-array/description/
// https://leetcode.com/problems/subarray-sum-equals-k/description/
// https://leetcode.com/problems/subarrays-with-k-different-integers/description/
// https://leetcode.com/problems/count-number-of-nice-subarrays/description/
// https://leetcode.com/problems/binary-subarrays-with-sum/description/
// https://leetcode.com/problems/subarray-product-less-than-k/description/
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/