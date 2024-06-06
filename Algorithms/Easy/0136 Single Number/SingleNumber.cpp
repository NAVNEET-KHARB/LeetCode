#include <bits/stdc++.h>
using namespace std;

// Runtime - 11ms || Memory - 19.25 MB
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};

// Runtime - 18ms || Memory - 19.26 MB
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xorr = 0;
        for (int i : nums)
        {
            xorr = xorr ^ i;
        }
        return xorr;
    }
};

int main()
{
    return 0;
}