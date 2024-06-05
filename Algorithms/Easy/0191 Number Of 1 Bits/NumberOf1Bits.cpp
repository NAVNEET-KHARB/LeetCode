#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 7.41 MB
class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }
};

int main()
{
    return 0;
}