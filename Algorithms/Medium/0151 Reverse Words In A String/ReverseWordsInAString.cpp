#include <bits/stdc++.h>
using namespace std;

// Runtime - 3ms || Memory - 8.33 MB
class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        int start = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
            {
                start = i;
            }
            if (s[i] != ' ' && (i == n - 1 || s[i + 1] == ' '))
            {
                reverse(s.begin() + start, s.begin() + i + 1);
            }
        }
        int j = 0;
        while (j < n && s[j] == ' ')
        {
            j++;
        }
        s = s.substr(j);
        j = s.length() - 1;
        while (j >= 0 && s[j] == ' ')
        {
            j--;
        }
        s = s.substr(0, j + 1);
        int k = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != ' ' || (i > 0 && s[i] == ' ' && s[i - 1] != ' '))
            {
                s[k++] = s[i];
            }
        }
        s.resize(k);

        return s;
    }
};

int main()
{
    return 0;
}