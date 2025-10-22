// // https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// // brute force

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// const int mx = 1e7 + 123;
// ll ara[mx];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     string str = "aaabcdeaa";

//     int max_len = 0;

//     // map<char, int> hash_map;
//     set<char> hash_set;

//     for (int i = 0; i < str.length(); i++)
//     {
//         // hash_map[str[i]]++;
//         hash_set.insert(str[i]);

//         if ((int)hash_set.size() == 1)
//         {
//             max_len = max(max_len, 1);
//         }
//         for (int j = i + 1; j < str.length(); j++)
//         {
//             hash_set.insert(str[j]);

//             int len = j - i + 1;

//             if (len == (int)hash_set.size())
//             {
//                 max_len = max(max_len, len);
//             }
//         }
//         hash_set.clear();
//     }
//     cout << max_len << endl;
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

    string str = "abcabcbb";

    int max_len = 0;
    set<char> hash_set;
    int left = 0; // two pointer apporach

    for (int right = 0; right < str.length(); right++)
    {

        if (hash_set.find(str[right]) != hash_set.end())
        {
            // duplicate exist

            while (left < right and hash_set.find(str[right]) != hash_set.end())
            {
                hash_set.erase(str[left]);
                // as the item of the left pointer already exist in the set so we are removing it

                left++; // pushing left pointer to the right
            }
        }

        hash_set.insert(str[right]);
        max_len = max(max_len, right - left + 1);
    }

    cout << max_len << endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}