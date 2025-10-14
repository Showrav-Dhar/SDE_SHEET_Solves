#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {2,3,1,4};
    int target = 4;
    map<int, int> hashDB;
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int second_item = target - nums[i];
        if (hashDB.find(second_item) != hashDB.end())
        { // means the item is present in the array
            idx1 = i;
            idx2 = hashDB[second_item];
            break;
        }
        else
        {
            // store the current element in the hashMap along with its index
            hashDB[nums[i]] = i;
        }
    }

    cout << idx1 << " " << idx2 << endl;

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
}