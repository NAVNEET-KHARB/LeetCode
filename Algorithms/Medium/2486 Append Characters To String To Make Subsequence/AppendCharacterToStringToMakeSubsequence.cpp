#include <bits/stdc++.h>
using namespace std;

// Runtime - 15ms || Memory - 11.97 MB
class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int first = 0, longestPrefix = 0;
        int l1 = s.length();
        int l2 = t.length();
        while (first < l1 && longestPrefix < l2)
        {
            if (s[first] == t[longestPrefix])
            {
                longestPrefix++;
            }
            first++;
        }
        return t.length() - longestPrefix;
    }
};

int main()
{
    return 0;
}