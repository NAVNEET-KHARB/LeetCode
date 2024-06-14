#include <bits/stdc++.h>
using namespace std;

// Runtime - 7ms | Memory - 9.30 MB
class Solution
{
public:
    int numerical(char roman)
    {
        if (roman == 'I')
            return 1;
        else if (roman == 'V')
            return 5;
        else if (roman == 'X')
            return 10;
        else if (roman == 'L')
            return 50;
        else if (roman == 'C')
            return 100;
        else if (roman == 'D')
            return 500;
        return 1000;
    }
    int romanToInt(string s)
    {
        int n = s.length();
        if (n == 1)
            return numerical(s[0]);
        int integerNum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (numerical(s[i]) < numerical(s[i + 1]))
            {
                integerNum -= numerical(s[i]);
            }
            else
            {
                integerNum += numerical(s[i]);
            }
        }
        integerNum += numerical(s[n - 1]);
        return integerNum;
    }
};

// Runtime - 7ms | Memory - 12.73 MB
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> rome;
        rome['I'] = 1;
        rome['V'] = 5;
        rome['X'] = 10;
        rome['L'] = 50;
        rome['C'] = 100;
        rome['D'] = 500;
        rome['M'] = 1000;
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (rome[s[i]] < rome[s[i + 1]])
            {
                ans -= rome[s[i]];
            }
            else
            {
                ans += rome[s[i]];
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}