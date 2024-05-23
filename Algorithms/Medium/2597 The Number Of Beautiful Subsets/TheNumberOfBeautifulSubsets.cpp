#include <bits/stdc++.h>
using namespace std;

// Runtime - 12ms || Memory - 38.67 MB
class Solution
{
private:
    int countBeautifulSubsets(vector<pair<int, int>> &subsets, int numSubsets, int difference, int i, vector<int> &counts)
    {
        if (i == numSubsets)
        {
            return 1;
        }
        if (counts[i] != -1)
        {
            return counts[i];
        }
        int skip = countBeautifulSubsets(subsets, numSubsets, difference, i + 1, counts);
        int take = (1 << subsets[i].second) - 1;
        if (i + 1 < numSubsets && subsets[i + 1].first - subsets[i].first == difference)
        {
            take *= countBeautifulSubsets(subsets, numSubsets, difference, i + 2, counts);
        }
        else
        {
            take *= countBeautifulSubsets(subsets, numSubsets, difference, i + 1, counts);
        }

        return counts[i] = skip + take;
    }

public:
    int beautifulSubsets(vector<int> &nums, int difference)
    {
        int totCount = 1;
        map<int, map<int, int>> freqMap;
        for (int &num : nums)
        {
            freqMap[num % difference][num]++;
        }
        for (auto &fr : freqMap)
        {
            vector<pair<int, int>> subsets(fr.second.begin(), fr.second.end());
            vector<int> counts(subsets.size(), -1);
            totCount *= countBeautifulSubsets(subsets, subsets.size(), difference, 0, counts);
        }
        return totCount - 1;
    }
};

int main()
{
    return 0;
}