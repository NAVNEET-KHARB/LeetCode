#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 8.19 MB
class Solution
{
public:
    void allSubSets(vector<int> &nums, int index, vector<int> &subset, vector<vector<int>> &subsets, int size)
    {
        if (index >= size)
        {
            subsets.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        allSubSets(nums, index + 1, subset, subsets, size);
        subset.pop_back();
        allSubSets(nums, index + 1, subset, subsets, size);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> subset;
        vector<vector<int>> subsets;
        int index = 0;
        int size = nums.size();
        allSubSets(nums, index, subset, subsets, size);
        return subsets;
    }
};

// Runtime - 4ms || Memory - 8.37 MB
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int numSubset = 1 << n;
        vector<vector<int>> ans;
        for (int num = 0; num < numSubset; num++)
        {
            vector<int> subset;
            for (int i = 0; i < n; i++)
            {
                if (num & (1 << i))
                {
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};

int main()
{
    return 0;
}