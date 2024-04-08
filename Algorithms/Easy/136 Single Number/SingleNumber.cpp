#include <bits/stdc++.h>
using namespace std;

// Runtime - 18ms || Memory - 19.26 MB
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xorr = 0;
        for (int i : nums)
        {
            xorr = xorr ^ i;
        }
        return xorr;
    }
};

int main()
{
    return 0;
}