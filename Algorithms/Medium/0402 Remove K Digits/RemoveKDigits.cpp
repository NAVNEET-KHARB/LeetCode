#include <bits/stdc++.h>
using namespace std;

// Runtime - 8ms || Memory - 10.07 MB
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k == num.size())
            return "0";
        stack<char> stk;
        for (char digit : num)
        {
            while (!stk.empty() && k > 0 && stk.top() > digit)
            {
                stk.pop();
                k--;
            }
            stk.push(digit);
        }
        while (k > 0)
        {
            stk.pop();
            k--;
        }
        string result;
        while (!stk.empty())
        {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());
        int start = 0;
        while (start < result.size() && result[start] == '0')
        {
            start++;
        }
        if (start == result.size())
            return "0";
        return result.substr(start);
    }
};

int main()
{
    return 0;
}