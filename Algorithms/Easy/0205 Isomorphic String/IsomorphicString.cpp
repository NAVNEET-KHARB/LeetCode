#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 8.24 MB
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        if (s.length() == 0)
            return true;
        int mapleft[256] = {0};
        int mapright[256] = {0};
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); i++)
        {
            left = s[i];
            right = t[i];
            if (mapleft[left] == 0 && mapright[right] == 0)
            {
                mapleft[left] = right;
                mapright[right] = left;
            }
            else
            {
                if (mapleft[left] != right || mapright[right] != left)
                    return false;
            }
        }
        return true;
    }
};

// Runtime - 4ms || Memory - 9.33 MB
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> sMap, tMap;
        for (int i = 0; i < s.length(); i++)
        {
            if (sMap.find(s[i]) == sMap.end() && tMap.find(t[i]) == tMap.end())
            {
                sMap[s[i]] = t[i];
                tMap[t[i]] = s[i];
            }
            else
            {
                if (sMap[s[i]] != t[i] || tMap[t[i]] != s[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}