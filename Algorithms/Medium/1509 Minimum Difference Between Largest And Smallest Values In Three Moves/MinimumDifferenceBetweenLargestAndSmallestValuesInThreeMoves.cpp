#include <bits/stdc++.h>
using namespace std;

// Runtime - 65ms || Memory - 37.56 MB
class Solution
{
public:
    static int minDifference(vector<int> &nums)
    {
        const int n = nums.size();
        if (n <= 4)
            return 0;
        nth_element(nums.begin(), nums.begin() + 4, nums.end());
        vector<int> small(nums.begin(), nums.begin() + 4);
        sort(small.begin(), small.end());
        nth_element(nums.begin(), nums.begin() + 4, nums.end(), greater<int>());
        vector<int> big(nums.begin(), nums.begin() + 4);
        sort(big.begin(), big.end());
        int min_diff = INT_MAX;
        for (int i = 0; i <= 3; ++i)
            min_diff = min(min_diff, big[i] - small[i]);
        return min_diff;
    }
};

int main()
{
    return 0;
}