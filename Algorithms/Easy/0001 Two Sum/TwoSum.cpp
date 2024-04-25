#include <bits/stdc++.h>
using namespace std;

// Runtime - 45ms || Memory - 12.72 MB
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// Runtime - 6ms || Memory - 13.61 MB
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            int current = nums[i];
            int required = target - current;
            if (mpp.find(required) != mpp.end())
            {
                return {mpp[required], i};
            }
            mpp[current] = i;
        }
        return {};
    }
};

int main()
{
    return 0;
}