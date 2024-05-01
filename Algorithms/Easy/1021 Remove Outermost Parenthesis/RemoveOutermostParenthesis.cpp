#include <bits/stdc++.h>
using namespace std;

// Runtime - 5ms || Memory - 7.96 MB
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int count = 0;
        string result = "";
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '(')
            {
                if (count > 0)
                {
                    result += ch;
                }
                count++;
            }
            else
            {
                count--;
                if (count > 0)
                {
                    result += ch;
                }
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}