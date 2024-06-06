#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 7.20 MB
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int ans = start ^ goal;
        int count = 0;
        for (int i = 0; i < 31; i++)
        {
            if (ans & (1 << i))
                count++;
        }
        return count;
    }
};

int main()
{
    return 0;
}