#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 8.12 MB
class Solution
{
public:
    int myAtoi(string s)
    {
        long long result = 0;
        int ptr = 0;
        int sign = 1;
        while (ptr < s.size() && s[ptr] == ' ')
        {
            ptr++;
        }
        if (ptr < s.size())
        {
            if (s[ptr] == '-')
            {
                sign = -1;
                ptr++;
            }
            else if (s[ptr] == '+')
            {
                ptr++;
            }
        }
        while (ptr < s.size() && s[ptr] >= '0' && s[ptr] <= '9')
        {
            result = result * 10 + (s[ptr] - '0');
            if (sign == 1 && result > INT_MAX)
            {
                return INT_MAX;
            }
            if (sign == -1 && -result < INT_MIN)
            {
                return INT_MIN;
            }
            ptr++;
        }
        return static_cast<int>(result * sign);
    }
};

int main()
{
    return 0;
}