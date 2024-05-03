#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 7.43 MB
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int i = 0, j = 0, n1 = 0, n2 = 0;
        int s1 = version1.length(), s2 = version2.length();
        while (i < s1 || j < s2)
        {
            while (i < s1 && version1[i] != '.')
            {
                n1 = n1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < s2 && version2[j] != '.')
            {
                n2 = n2 * 10 + (version2[j] - '0');
                j++;
            }
            if (n1 > n2)
                return 1;
            if (n1 < n2)
                return -1;
            n1 = 0, n2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};

int main()
{
    return 0;
}