#include <bits/stdc++.h>
using namespace std;

// Runtime - 9ms || Memory - 14.27 MB
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        for (int n : nums)
        {
            mpp[n]++;
        }
        vector<int> ans;
        for (auto pair : mpp)
        {
            if (pair.second == 1)
            {
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}