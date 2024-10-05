class Solution {
    int solve(int ind, int tar, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            return (tar%coins[0] == 0);
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int notTake = solve(ind-1,tar,coins,dp);
        int take = 0;
        if(coins[ind]<=tar) take = solve(ind,tar-coins[ind],coins,dp);
        return dp[ind][tar] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};