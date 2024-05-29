#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 7.51 MB
class Solution
{
public:
    int numSteps(string s)
    {
        int carry = 0, steps = 0;
        for (int i = s.length() - 1; i > 0; i--)
        {
            if ((s[i] - '0') + carry == 1)
            {
                steps += 2;
                carry = 1;
            }
            else
            {
                steps++;
            }
        }
        return steps + carry;
    }
};

int main()
{
    return 0;
}