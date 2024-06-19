#include <bits/stdc++.h>
using namespace std;

// Runtime - 43ms || Memory - 40.83 MB
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = difficulty.size();
        int m = worker.size();
        vector<pair<int, int>> jobEarn;
        jobEarn.push_back({0, 0});
        for (int i = 0; i < n; i++)
        {
            jobEarn.push_back({difficulty[i], profit[i]});
        }
        sort(jobEarn.begin(), jobEarn.end());
        for (int i = 0; i < jobEarn.size() - 1; i++)
        {
            jobEarn[i + 1].second = max(jobEarn[i].second, jobEarn[i + 1].second);
        }
        int maxProfit = 0;
        for (int i = 0; i < m; i++)
        {
            int ability = worker[i];
            int l = 0, r = jobEarn.size() - 1, jobProfit = 0;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (jobEarn[mid].first <= ability)
                {
                    jobProfit = max(jobProfit, jobEarn[mid].second);
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            maxProfit += jobProfit;
        }
        return maxProfit;
    }
};

int main()
{
    return 0;
}