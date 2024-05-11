#include <bits/stdc++.h>
using namespace std;

// Runtime - 27ms || Memory - 24.68 MB
class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        vector<pair<double, int>> workers(n);

        // Create a vector of pairs (wage-to-quality ratio, quality)
        for (int i = 0; i < n; i++)
        {
            workers[i] = {static_cast<double>(wage[i]) / quality[i],
                          quality[i]};
        }

        // Sort workers based on wage-to-quality ratio in ascending order
        sort(workers.begin(), workers.end());

        int totalQuality = 0;
        double minCost = DBL_MAX;
        priority_queue<int> maxHeap;

        for (const auto &worker : workers)
        {
            totalQuality += worker.second;
            maxHeap.push(worker.second);

            if (maxHeap.size() > k)
            {
                totalQuality -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == k)
            {
                minCost = min(minCost, totalQuality * worker.first);
            }
        }

        return minCost;
    }
};

int main()
{
    return 0;
}