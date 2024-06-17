#include <bits/stdc++.h>
using namespace std;

// Runtime - 116ms || Memory - 9.96 MB
class Solution
{
public:
    int beautySum(string s)
    {
        if (s.length() <= 1)
            return 0;
        int bsum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            vector<int> freq(26, 0);
            freq[s[i] - 'a']++;

            for (int j = i + 1; j < s.length(); j++)
            {
                freq[s[j] - 'a']++;
                int mini = INT_MAX;
                int maxi = 0;
                for (int x = 0; x < 26; x++)
                {
                    maxi = max(maxi, freq[x]);
                    if (freq[x] != 0)
                    {
                        mini = min(mini, freq[x]);
                    }
                }
                bsum += (maxi - mini);
            }
        }
        return bsum;
    }
};

int main()
{
    return 0;
}