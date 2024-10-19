class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(2,0);
        vector<int> temp(2,0);
        for(int ind = n-1; ind>=0; ind--){
            temp[1] = max(-prices[ind]+dp[0],dp[1]);
            temp[0] = max(prices[ind]-fee+dp[1],dp[0]);
            dp = temp;
        }
        return dp[1];
    }
};