#include <bits/stdc++.h>
using namespace std;

// Runtime - 155ms || Memory - 134.74 MB
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 1)
            return false;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int remain = sum % k;
            if (mp.find(remain) != mp.end())
            {
                if (i - mp[remain] > 1)
                {
                    return true;
                }
            }
            else
            {
                mp[remain] = i;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}