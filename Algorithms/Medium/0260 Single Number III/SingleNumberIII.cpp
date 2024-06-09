#include <bits/stdc++.h>
using namespace std;

// Runtime - 5ms || Memory - 12.30 MB
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        long XORR = 0;
        for (auto &num : nums)
        {
            XORR ^= num;
        }
        int rightmost = (XORR & (XORR - 1)) ^ XORR;
        int b1 = 0, b2 = 0;
        for (auto &num : nums)
        {
            if (num & rightmost)
                b1 ^= num;
            else
                b2 ^= num;
        }
        return {b1, b2};
    }
};

// Runtime - 9ms || Memory - 14.27 MB
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        for (int n : nums)
        {
            mpp[n]++;
        }
        vector<int> ans;
        for (auto pair : mpp)
        {
            if (pair.second == 1)
            {
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}