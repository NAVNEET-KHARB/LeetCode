#include <bits/stdc++.h>
using namespace std;

// Runtime - 3ms || Memory - 11.74 MB
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0;
        int twos = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};

// Runtime - 3ms || Memory - 12.00 MB
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 3)
        {
            if (i == n - 1 || nums[i] != nums[i + 1])
            {
                return nums[i];
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}