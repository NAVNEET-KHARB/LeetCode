#include <bits/stdc++.h>
using namespace std;

// Runime - 0ms || Memory - 7.87 MB
class Solution
{
public:
    double myPow(double x, int n)
    {
        bool neg = false;
        if (n < 0)
            neg = true;
        n = abs(n);
        double ans = 1;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans = ans * x;
                n--;
            }
            else
            {
                x *= x;
                n /= 2;
            }
        }
        if (neg)
            return 1.0 / ans;
        return ans;
    }
};

int main()
{
    return 0;
}