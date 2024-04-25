#include <bits/stdc++.h>
using namespace std;

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