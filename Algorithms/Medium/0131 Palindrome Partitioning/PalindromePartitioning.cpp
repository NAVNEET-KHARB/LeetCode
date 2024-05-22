#include <bits/stdc++.h>
using namespace std;

// Runtime - 65ms || Memory - 52.74 MB
class Solution
{
public:
    bool isPalindrome(const string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }

    void palStrings(const string &s, int start, vector<string> &path,
                    vector<vector<string>> &result, int size)
    {
        if (start == size)
        {
            result.push_back(path);
            return;
        }
        for (int end = start + 1; end <= s.length(); ++end)
        {
            if (isPalindrome(s, start, end - 1))
            {
                path.push_back(s.substr(start, end - start));
                palStrings(s, end, path, result, size);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<string> path;
        vector<vector<string>> result;
        int n = s.length();
        palStrings(s, 0, path, result, n);
        return result;
    }
};

int main()
{
    return 0;
}