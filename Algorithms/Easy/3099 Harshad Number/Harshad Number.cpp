#include <bits/stdc++.h>
using namespace std;

// Runtime - 2ms | Memory - 7 MB
class Solution
{
public:
    int sumOfTheDigitsOfHarshadNumber(int x)
    {
        int sx = 0;
        int temp = x;
        while (temp)
        {
            sx += temp % 10;
            temp /= 10;
        }
        if (x % sx == 0)
            return sx;
        return -1;
    }
};

int main()
{
    return 0;
}