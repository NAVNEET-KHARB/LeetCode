#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 8.46 MB
class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        return XORSum(nums, 0, 0);
    }

private:
    int XORSum(vector<int> &nums, int index, int currentXOR)
    {
        if (index == nums.size())
            return currentXOR;
        int withElement = XORSum(nums, index + 1, currentXOR ^ nums[index]);
        int withoutElement = XORSum(nums, index + 1, currentXOR);
        return withElement + withoutElement;
    }
};

// Runtime - 83ms || Memory - 46.98 MB
class Solution
{
public:
    void subsetGen(vector<int> &nums, int index, vector<int> subset, vector<vector<int>> &subsets)
    {
        if (index == nums.size())
        {
            subsets.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        subsetGen(nums, index + 1, subset, subsets);
        subset.pop_back();
        subsetGen(nums, index + 1, subset, subsets);
    }
    int subsetXORSum(vector<int> &nums)
    {
        vector<vector<int>> subsets;
        subsetGen(nums, 0, {}, subsets);
        int ans = 0;
        for (auto &set : subsets)
        {
            int xorSet = 0;
            for (int n : set)
            {
                xorSet ^= n;
            }
            ans += xorSet;
        }
        return ans;
    }
};

int main()
{
    return 0;
}