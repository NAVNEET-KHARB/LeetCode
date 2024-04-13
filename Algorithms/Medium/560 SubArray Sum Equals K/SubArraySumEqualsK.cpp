#include <bits/stdc++.h>
using namespace std;

// Runtime - 69ms || Memory - 50.64MB
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int preSum = 0, count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            preSum += nums[i];
            int remain = preSum - k;
            count += mpp[remain];
            mpp[preSum]++;
        }
        return count;
    }
};

int main()
{
    return 0;
}