#include <bits/stdc++.h>
using namespace std;

// Runtime - 118ms || Memory - 69.09 MB
class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int minIncrements = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                int increment = nums[i - 1] + 1 - nums[i];
                minIncrements += increment;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return minIncrements;
    }
};

int main()
{
    return 0;
}