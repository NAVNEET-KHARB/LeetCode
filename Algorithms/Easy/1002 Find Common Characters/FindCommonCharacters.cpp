#include <bits/stdc++.h>
using namespace std;

// Runtime - 4ms || Memory - 11.58 MB
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<int> common_freq(26, INT_MAX);
        for (const auto &word : words)
        {
            vector<int> current_freq(26, 0);
            for (char c : word)
            {
                current_freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i)
            {
                common_freq[i] = min(common_freq[i], current_freq[i]);
            }
        }
        vector<string> result;
        for (int i = 0; i < 26; ++i)
        {
            while (common_freq[i] > 0)
            {
                result.push_back(string(1, 'a' + i));
                common_freq[i]--;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}