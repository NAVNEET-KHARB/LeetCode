#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 7.13 MB
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        return ((n & (n - 1)) == 0);
    }
};

int main()
{
    return 0;
}