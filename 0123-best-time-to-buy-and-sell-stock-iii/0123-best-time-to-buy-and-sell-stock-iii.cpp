class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2,vector<int>(3,0));
        vector<vector<int>> temp(2,vector<int>(3,0));
        for(int buy = 0; buy<=1; buy++){
            dp[buy][0] = 0;
        }
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap = 1; cap<=2; cap++){
                    if(buy){
                        temp[buy][cap] = max(-prices[ind]+dp[0][cap],dp[1][cap]);
                    }
                    else temp[buy][cap] = max(prices[ind]+dp[1][cap-1],dp[0][cap]);
                }
            }
            dp = temp;
        }
        return dp[1][2];
    }
};