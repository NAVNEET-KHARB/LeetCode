class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = INT_MAX;
        for(int j = 0; j<m; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                int st,ld,rd;
                st = ld = rd = matrix[i][j];
                st += dp[i-1][j];
                if(j>0) ld += dp[i-1][j-1];
                else ld += 1e9;
                if(j+1<m) rd += dp[i-1][j+1];
                else rd += 1e9;
                dp[i][j] = min(st,min(ld,rd));
            }
        }
        for(int j = 0; j<m; j++) ans = min(ans,dp[n-1][j]);
        return ans;
    }
};