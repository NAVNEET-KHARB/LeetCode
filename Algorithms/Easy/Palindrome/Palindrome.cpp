#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int temp = x;
        long rx = 0;
        while (temp)
        {
            rx = rx * 10 + temp % 10;
            temp /= 10;
        }
        return (x == rx);
        // Runtime - 7ms
        // Memory - 8.2MB
    }
};
int main()
{
    return 0;
}