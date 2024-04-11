#include <bits/stdc++.h>
using namespace std;

// Runtime - 72ms || Memory - 95.69 MB
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int cost = prices[i] - minPrice;
            profit = max(profit, cost);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};

int main()
{
    return 0;
}