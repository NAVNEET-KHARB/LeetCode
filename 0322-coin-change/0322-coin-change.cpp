class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,0);
        vector<int> temp(amount+1,0);
        for(int tar = 0; tar<=amount; tar++){
            if(tar%coins[0] == 0) dp[tar] = tar/coins[0];
            else dp[tar] = 1e9;
        }
        for(int i = 1; i<n; i++){
            for(int tar = 0; tar<=amount; tar++){
                int notTake = dp[tar];
                int take = INT_MAX;
                if(coins[i]<=tar) take = 1 + temp[tar-coins[i]];
                temp[tar] = min(notTake,take);
            }
            dp = temp;
        }
        return dp[amount]>=1e9?-1:dp[amount];
    }
};