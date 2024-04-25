#include <bits/stdc++.h>
using namespace std;

// Runtime - 19ms || Memory - 38.64 MB
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int continuous1 = 0;
        int maxContinuous1 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                continuous1++;
                maxContinuous1 = max(maxContinuous1, continuous1);
            }
            else if (nums[i] != 1)
            {
                continuous1 = 0;
            }
        }
        return maxContinuous1;
    }
};

int main()
{
    return 0;
}