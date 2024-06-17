#include <bits/stdc++.h>
using namespace std;

// Runtime - 4ms || Memory - 7.10 MB
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long long start = 0;
        long long end = sqrt(c);
        while (start <= end)
        {
            long long squareSum = (start * start) + (end * end);
            if (squareSum == c)
                return true;
            else if (squareSum > c)
                end--;
            else
                start++;
        }
        return false;
    }
};

int main()
{
    return 0;
}