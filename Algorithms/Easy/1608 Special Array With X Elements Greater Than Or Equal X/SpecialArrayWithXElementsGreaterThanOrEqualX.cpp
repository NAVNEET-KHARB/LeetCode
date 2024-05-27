#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 10.26 MB
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= i + 1)
            {
                if (i == n - 1 || nums[i + 1] < i + 1)
                {
                    return i + 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}