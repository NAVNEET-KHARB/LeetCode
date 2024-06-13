#include <bits/stdc++.h>
using namespace std;

// Runtime - 4ms || Memory - 8.57 MB
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t);
    }
};

// Runtime - 4ms || Memory - 8.47 MB
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        int array[26];
        for (int i = 0; i < s.length(); i++)
        {
            array[s[i] - 'a']++;
            array[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (array[i] != 0)
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}