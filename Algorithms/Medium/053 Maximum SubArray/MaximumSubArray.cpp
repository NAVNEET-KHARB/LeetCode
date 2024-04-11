#include <bits/stdc++.h>
using namespace std;

// Runtime - 71ms || Memory - 70.24 MB
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // Using Kadane's Algo
        int maxi = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum < 0)
                sum = 0;
            sum += nums[i];
            maxi = max(sum, maxi);
        }
        return maxi;
    }
};

int main()
{
    return 0;
}