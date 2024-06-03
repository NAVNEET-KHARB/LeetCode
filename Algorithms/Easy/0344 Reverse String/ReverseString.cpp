#include <bits/stdc++.h>
using namespace std;

// Runtime - 14ms || Memory - 26.86 MB
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int first = 0;
        int last = s.size() - 1;
        while (first < last)
        {
            char c = s[first];
            s[first] = s[last];
            s[last] = c;
            first++;
            last--;
        }
    }
};

int main()
{
    return 0;
}