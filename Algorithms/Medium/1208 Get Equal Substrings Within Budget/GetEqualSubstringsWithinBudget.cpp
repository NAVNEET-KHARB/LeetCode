#include <bits/stdc++.h>
using namespace std;

// Runtime - 6ms || Memory - 8.76 MB
class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int len = s.length();
        int ans = 0;
        int cost = 0;
        int remInd = 0;
        for (int i = 0; i < len; i++)
        {
            cost += abs(int(s[i]) - int(t[i]));
            while (cost > maxCost)
            {
                cost -= abs(int(s[remInd]) - int(t[remInd]));
                remInd++;
            }
            ans = max(ans, i - remInd + 1);
        }
        return ans;
    }
};

int main()
{
    return 0;
}