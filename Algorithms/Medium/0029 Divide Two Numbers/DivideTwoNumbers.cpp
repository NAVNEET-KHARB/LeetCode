#include <bits/stdc++.h>
using namespace std;

// Runtime - 5ms || Memory - 7.70 MB
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == divisor)
            return 1;
        bool sign = true;
        if (dividend >= 0 && divisor < 0)
            sign = false;
        if (dividend < 0 && divisor > 0)
            sign = false;
        long n = labs(dividend);
        long d = labs(divisor);
        long quotient = 0;
        while (n >= d)
        {
            int power = 0;
            while (n >= (d << (power + 1)))
            {
                power++;
            }
            quotient += 1 << power;
            n -= d << power;
        }
        if (quotient == (1 << 31) && sign)
            return INT_MAX;
        if (quotient == (1 << 31) && !sign)
            return INT_MIN;
        return sign ? (int)quotient : (int)-quotient;
    }
};

int main()
{
    return 0;
}