#include <bits/stdc++.h>
using namespace std;

// Runtime - 117ms || Memory - 88.06 MB
class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 1));

        fillDPTable(nums, k, dp);

        return findMaxSubsequenceLength(dp);
    }

private:
    void fillDPTable(vector<int> &nums, int k, vector<vector<int>> &dp)
    {
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int remainder = (nums[i] + nums[j]) % k;
                dp[i][remainder] = max(dp[i][remainder], dp[j][remainder] + 1);
            }
        }
    }

    int findMaxSubsequenceLength(vector<vector<int>> &dp)
    {
        int maxLength = 0;
        for (auto &row : dp)
        {
            for (int length : row)
            {
                maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }
};

int main()
{
    return 0;
}