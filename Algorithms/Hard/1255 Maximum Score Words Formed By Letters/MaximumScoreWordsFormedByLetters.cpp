#include <bits/stdc++.h>
using namespace std;

// Runtime - 5ms || Memory - 16.98 MB
class Solution
{
public:
    void solve(int i, int &n, vector<int> &mp, vector<int> &score, int &ans, int sum, vector<string> &words)
    {
        ans = max(ans, sum);

        if (i >= n)
            return;

        vector<int> tempMap = mp;

        int j = 0;
        int sum2 = 0;

        for (j = 0; j < words[i].length(); j++)
        {
            tempMap[words[i][j] - 'a']--;
            sum2 += score[words[i][j] - 'a'];
            if (tempMap[words[i][j] - 'a'] < 0)
                break;
        }

        if (j == words[i].length())
        {
            solve(i + 1, n, tempMap, score, ans, sum + sum2, words);
        }
        solve(i + 1, n, mp, score, ans, sum, words);
    }
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        vector<int> mp(26, 0);
        for (char i : letters)
        {
            mp[i - 'a']++;
        }
        int ans = 0;
        int n = words.size();
        solve(0, n, mp, score, ans, 0, words);
        return ans;
    }
};

// Runtime - 96ms || Memory - 83.44 MB
class Solution
{
public:
    void findSubsetsRecursiveHelper(vector<string> &strings, int index, vector<string> &currentSubset, vector<vector<string>> &subSets, int size)
    {
        if (index == size)
        {
            subSets.push_back(currentSubset);
            return;
        }
        currentSubset.push_back(strings[index]);
        findSubsetsRecursiveHelper(strings, index + 1, currentSubset, subSets, size);
        currentSubset.pop_back();
        findSubsetsRecursiveHelper(strings, index + 1, currentSubset, subSets, size);
    }

    int wordScore(string word, vector<int> &charCountT, vector<int> &score)
    {
        int len = word.length();
        int iscore = 0;
        vector<int> tempCount = charCountT;

        for (char c : word)
        {
            if (tempCount[c - 'a'] > 0)
            {
                iscore += score[c - 'a'];
                tempCount[c - 'a']--;
            }
            else
            {
                return 0;
            }
        }
        charCountT = tempCount;
        return iscore;
    }

    int countScore(vector<string> subSet, vector<int> &charCountT, vector<int> &score)
    {
        int totalScore = 0;
        for (string word : subSet)
        {
            int wordScoreValue = wordScore(word, charCountT, score);
            if (wordScoreValue == 0)
            {
                return 0;
            }
            totalScore += wordScoreValue;
        }
        return totalScore;
    }

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        int wordsLen = words.size();
        vector<int> charCount(26, 0);
        for (char c : letters)
        {
            charCount[c - 'a']++;
        }
        vector<vector<string>> subSets;
        vector<string> currentSubset;
        findSubsetsRecursiveHelper(words, 0, currentSubset, subSets, wordsLen);
        int maxScore = 0;
        for (const auto &subset : subSets)
        {
            vector<int> charCountT = charCount;
            maxScore = max(maxScore, countScore(subset, charCountT, score));
        }
        return maxScore;
    }
};

int main()
{
    return 0;
}