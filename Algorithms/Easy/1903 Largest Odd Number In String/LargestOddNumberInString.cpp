#include <bits/stdc++.h>
using namespace std;

// Runtime - 24ms || Memory - 16.22 MB
class Solution
{
public:
    string largestOddNumber(string num)
    {
        int a = 0, j = 0;
        int n = num.length();
        for (int i = 0; i < n; i++)
        {
            if ((num[i] - '0') % 2 == 1)
            {
                j = a;
                a++;
                j++;
            }
            else
                a++;
        }
        num = num.substr(0, j);
        return num;
    }
};

int main()
{
    return 0;
}