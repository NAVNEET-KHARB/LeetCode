#include <bits/stdc++.h>
using namespace std;

// Runtime - 104ms || Memory - 138.43 MB
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int operations = 0;
        for (int i = 0; i <= n - 3; ++i)
        {
            if (nums[i] == 0)
            {
                nums[i] = 1 - nums[i];
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
                ++operations;
            }
        }
        if (nums[n - 1] == 0 || nums[n - 2] == 0)
        {
            return -1;
        }
        return operations;
    }
};

int main()
{
    return 0;
}