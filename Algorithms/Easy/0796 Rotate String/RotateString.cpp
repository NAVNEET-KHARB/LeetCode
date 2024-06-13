#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 8.40 MB
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            char c = s[0];
            s.erase(s.begin());
            s = s + c;
            if (s == goal)
                return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}