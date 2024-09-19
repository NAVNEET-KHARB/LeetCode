class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int minCost = prices[0]+prices[1];
        if(minCost<=money) return money-minCost;
        return money;
    }
};