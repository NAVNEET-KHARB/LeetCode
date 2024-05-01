#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 7.39 MB
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        string ans = "";
        bool once = true;
        for (char c : word)
        {
            if (c == ch && once)
            {
                ans += c;
                reverse(ans.begin(), ans.end());
                once = false;
            }
            else
            {
                ans += c;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}