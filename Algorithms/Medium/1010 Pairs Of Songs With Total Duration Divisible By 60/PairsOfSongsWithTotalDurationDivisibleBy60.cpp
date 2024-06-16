#include <bits/stdc++.h>
using namespace std;

// Runtime - 24ms || Memory - 30.48 MB
class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        vector<int> timeRem(60, 0);
        int ans = 0;
        for (auto &t : time)
        {
            int remainder = t % 60;
            int complement = (60 - remainder) % 60;
            ans += timeRem[complement];
            timeRem[remainder]++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}