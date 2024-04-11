#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 14.51 MB
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int breakInd = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                breakInd = i;
                break;
            }
        }
        if (breakInd == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > breakInd; i--)
        {
            if (nums[i] > nums[breakInd])
            {
                swap(nums[i], nums[breakInd]);
                break;
            }
        }
        reverse(nums.begin() + breakInd + 1, nums.end());
    }
};

int main()
{
    return 0;
}