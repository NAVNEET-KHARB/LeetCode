class Solution {
    int solve(int ind, int buy, int fee, int n, vector<int> &prices, vector<vector<int>> &dp){
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            return dp[ind][buy] = max(-prices[ind]+solve(ind+1,0,fee,n,prices,dp),solve(ind+1,1,fee,n,prices,dp));
        }
       return dp[ind][buy] = max(prices[ind]-fee+solve(ind+1,1,fee,n,prices,dp),solve(ind+1,0,fee,n,prices,dp)); 
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,fee,n,prices,dp);
    }
};