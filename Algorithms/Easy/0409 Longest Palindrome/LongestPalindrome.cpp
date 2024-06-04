#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 9.02 MB
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> freqMap;
        for (char c : s)
        {
            freqMap[c]++;
        }
        int res = 0;
        bool hasOddFreq = false;
        for (auto record : freqMap)
        {
            int freq = record.second;
            if (freq % 2 == 0)
            {
                res += freq;
            }
            else
            {
                res += freq - 1;
                hasOddFreq = true;
            }
        }
        if (hasOddFreq)
            res += 1;
        return res;
    }
};

int main()
{
    return 0;
}