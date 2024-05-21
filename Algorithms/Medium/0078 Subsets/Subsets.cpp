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

int main()
{
    return 0;
}