class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxPro = 0;
        int minPrice = prices[0];
        for(int i = 1; i<n; i++){
            int cost = prices[i] - minPrice;
            minPrice = min(prices[i],minPrice);
            maxPro = max(maxPro,cost);
        }
        return maxPro;
    }
};