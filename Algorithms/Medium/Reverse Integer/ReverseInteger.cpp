#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long rx = 0;
        while (x)
        {
            rx = rx * 10 + x % 10;
            x = x / 10;
        }
        if (rx > INT32_MAX || rx < INT32_MIN)
            rx = 0;
        return rx;
    }
    // Runtime - 0ms
    // Memory - 7.41 MB
};

int main()
{
    return 0;
}