#include <bits/stdc++.h>
using namespace std;

// Runtime - 134ms || Memory - 85.52 MB
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        vector<pair<int, int>> capProfit;
        for (int i = 0; i < n; i++)
        {
            capProfit.push_back({capital[i], profits[i]});
        }
        sort(capProfit.begin(), capProfit.end());
        priority_queue<int> maxHeap;
        int current = 0;
        for (int i = 0; i < k; i++)
        {
            while (current < n && capProfit[current].first <= w)
            {
                maxHeap.push(capProfit[current].second);
                current++;
            }
            if (maxHeap.empty())
                break;
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};

int main()
{
    return 0;
}