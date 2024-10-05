class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> dp(amount+1,0);
        vector<long long> temp(amount+1,0);
        for(int tar = 0; tar<=amount; tar++){
            dp[tar] = (tar%coins[0]==0);
        }
        for(int ind = 1; ind<n; ind++){
            for(int tar = 0; tar<=amount; tar++){
                int notTake = dp[tar];
                int take = 0;
                if(coins[ind]<=tar) take = temp[tar-coins[ind]];
                temp[tar] = (long long)take+(long long)notTake;
            }
            dp = temp;
        }
        return (int)dp[amount];
    }
};