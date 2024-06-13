#include <bits/stdc++.h>
using namespace std;

// Runtime - 3ms || Memory - 8.41 MB
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.length();
        for (int i = 0; i < n; i += 2 * k)
        {
            if (i + k <= n)
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else
            {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

int main()
{
    return 0;
}