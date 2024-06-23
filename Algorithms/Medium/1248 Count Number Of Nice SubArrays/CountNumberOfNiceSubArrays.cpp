#include <bits/stdc++.h>
using namespace std;

// Runtime - 85ms || Memory - 73.16 MB
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        cnt[0] = 1;
        int ans = 0, oddcnt = 0;
        for (int v : nums)
        {
            oddcnt += v & 1;
            if (oddcnt - k >= 0)
            {
                ans += cnt[oddcnt - k];
            }
            cnt[oddcnt]++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}