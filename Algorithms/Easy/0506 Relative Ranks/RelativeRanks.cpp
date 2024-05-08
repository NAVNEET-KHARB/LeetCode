#include <bits/stdc++.h>
using namespace std;

// Runtime - 6ms || Memory - 14.26 MB
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        unordered_map<int, int> store;
        for (int i = 0; i < n; i++)
        {
            store[score[i]] = i;
        }
        sort(score.begin(), score.end(), greater<int>());
        vector<string> result(n);
        for (int i = 0; i < n; i++)
        {
            int index = store[score[i]];
            if (i == 0)
            {
                result[index] = "Gold Medal";
            }
            else if (i == 1)
            {
                result[index] = "Silver Medal";
            }
            else if (i == 2)
            {
                result[index] = "Bronze Medal";
            }
            else
                result[index] = to_string(i + 1);
        }
        return result;
    }
};

int main()
{
    return 0;
}