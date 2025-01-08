class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        int minBuy = prices[0];
        int n = prices.length;
        for(int i = 1; i<n; i++){
            profit = Math.max(profit, prices[i] - minBuy);
            minBuy = Math.min(minBuy,prices[i]);
        }
        return profit;
    }
}