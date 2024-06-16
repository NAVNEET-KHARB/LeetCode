#include <bits/stdc++.h>
using namespace std;

// Runtime - 126ms || Memory - 137.82 MB
class Solution
{
public:
    long long countCompleteDayPairs(vector<int> &hours)
    {
        vector<int> hourRem(24, 0);
        long long ans = 0;
        for (auto &h : hours)
        {
            int remainder = h % 24;
            int complement = (24 - remainder) % 24;
            ans += hourRem[complement];
            hourRem[remainder]++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}