// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {

//     // BRUTE FORCE _

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> nums1 = {1, 2, 3, 0, 0, 0};
//     vector<int> nums2 = {2, 5, 6};

//     int m = 3;
//     int n = 3;

//     int i = 0, j = 0, k = m;

//     for (int i = 0; i < nums1.size(); i++)
//     {
//         if (nums1[i] < nums2[j])
//         {
//             continue;
//         }
//         else if (nums1[i] > nums2[j])
//         {
//             nums1[k] = nums1[m-1];
//         }
//     }

//     cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
// }

// OPTIMAL

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx = 1e7 + 123;
ll ara[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums1 = {2, 5, 6, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3};

    int m = 3;
    int n = 3;


    int i = 0;         // pointing nums1
    int j = 0;         // poining nums2
    int limit = m - 1; // pointing to the last item of nums1 array;

    for (i = 0; i < nums1.size(); i++)
    {
        if (j < n and nums2[j] <= nums1[i])
        {

            // shift all elements 1 position right
            // including the current element
            // K  nums1 array er last theke shuru hoi
            // goes until current item in nums1 array
            for (int k = limit; k >= i; k--)
            {
                swap(nums1[k], nums1[k + 1]);
            }
            limit++; // limit now points to the last item of the updated nums1 array
            // now nums1[i] = 0;
            nums1[i] = nums2[j];
            j++;
        }
    }

    int current_empty_position_index = limit + 1;

    for (int i = current_empty_position_index; i < nums1.size(); i++)
    {
        nums1[i] = nums2[j];
        j++;
    }
    for (auto it : nums1)
    {
        cout << it << " ";
    }

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}