#include <bits/stdc++.h>
using namespace std;

// Runtime - 5ms || Memory - 7.62 MB
class Solution
{
public:
    string clearDigits(string s)
    {
        string result;
        for (char c : s)
        {
            if (isdigit(c))
            {
                if (!result.empty())
                {
                    result.pop_back();
                }
            }
            else
            {
                result.push_back(c);
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}