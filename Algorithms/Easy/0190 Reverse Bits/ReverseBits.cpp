#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 7.34 MB
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        long long result = 0;
        for (int i = 0; i < 32; i++)
        {
            long long leastSignificantBit = n & 1;
            n = n >> 1;
            result = result << 1;
            result = result | leastSignificantBit;
        }
        return result;
    }
};

int main()
{
    return 0;
}