#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 9.34 MB
class Solution
{
public:
    vector<string> solve(const string &s, unordered_map<string, int> &mpp, int start, unordered_map<int, vector<string>> &memo, int sSize)
    {
        if (memo.find(start) != memo.end())
        {
            return memo[start];
        }

        if (start == sSize)
        {
            return {""};
        }

        vector<string> results;
        for (int end = start + 1; end <= sSize; end++)
        {
            string word = s.substr(start, end - start);
            if (mpp.find(word) != mpp.end())
            {
                vector<string> subResults = solve(s, mpp, end, memo, sSize);
                for (const string &subResult : subResults)
                {
                    string space = subResult.empty() ? "" : " ";
                    results.push_back(word + space + subResult);
                }
            }
        }

        memo[start] = results;
        return results;
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, int> mpp;
        for (auto word : wordDict)
        {
            mpp[word]++;
        }
        int sSize = s.length();
        unordered_map<int, vector<string>> memo;
        vector<string> ans = solve(s, mpp, 0, memo, sSize);
        return ans;
    }
};

int main()
{
    return 0;
}