class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n,vector<long long>(amount+1,0));
        for(int tar = 0; tar<=amount; tar++){
            dp[0][tar] = (tar%coins[0]==0);
        }
        for(int ind = 1; ind<n; ind++){
            for(int tar = 0; tar<=amount; tar++){
                int notTake = dp[ind-1][tar];
                int take = 0;
                if(coins[ind]<=tar) take = dp[ind][tar-coins[ind]];
                dp[ind][tar] = (long long)take+(long long)notTake;
            }
        }
        return (int)dp[n-1][amount];
    }
};