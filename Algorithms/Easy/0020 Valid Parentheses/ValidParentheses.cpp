#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 7.53 MB
class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        if (n & 1)
            return false;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                    return false;
                char c = st.top();
                st.pop();
                if (s[i] == ')' && c == '(')
                    continue;
                else if (s[i] == ']' && c == '[')
                    continue;
                else if (s[i] == '}' && c == '{')
                    continue;
                else
                    return false;
            }
        }
        return st.empty();
    }
};

int main()
{
    return 0;
}