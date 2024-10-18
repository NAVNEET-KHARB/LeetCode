class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2,0);
        vector<int> temp(2,0);
        dp[0] = dp[1] = 0;
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<=1; j++){
                int profit;
                if(j){
                    profit = max(-prices[i]+dp[0],dp[1]);
                }else{
                    profit = max(prices[i]+dp[1],dp[0]);
                }
                temp[j] = profit;
            }
            dp = temp;
        }
        return dp[1];
    }
};