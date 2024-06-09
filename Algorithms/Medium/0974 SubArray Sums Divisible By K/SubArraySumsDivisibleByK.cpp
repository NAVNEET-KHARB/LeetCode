#include <bits/stdc++.h>
using namespace std;

// Runtime - 33ms || Memory - 35.02 MB
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int sum = 0, rem, subArrays = 0;
        for (auto &num : nums)
        {
            sum += num;
            rem = sum % k;
            if (rem < 0)
                rem += k;
            if (prefixSum.find(rem) != prefixSum.end())
            {
                subArrays += prefixSum[rem];
            }
            prefixSum[rem]++;
        }
        return subArrays;
    }
};

int main()
{
    return 0;
}