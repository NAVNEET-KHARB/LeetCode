#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 7.54 MB
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
            return x;
        int low = 1, high = x, ans = 0;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long val = mid * mid;
            if (val == x)
            {
                ans = mid;
                break;
            }
            else if (val < x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};

int main()
{
    return 0;
}