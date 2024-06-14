#include <bits/stdc++.h>
using namespace std;

// Runtime - 6ms || Memory - 10.82 MB
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }
        vector<pair<char, int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](const pair<char, int> &a, const pair<char, int> &b)
             { return a.second > b.second; });
        string result;
        for (const auto &p : freqVec)
        {
            result.append(p.second, p.first);
        }
        return result;
    }
};

int main()
{
    return 0;
}