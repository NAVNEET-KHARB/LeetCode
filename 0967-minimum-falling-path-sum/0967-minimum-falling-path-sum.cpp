class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m,-1);
        int ans = INT_MAX;
        for(int j = 0; j<m; j++){
            dp[j] = matrix[0][j];
        }
        for(int i = 1; i<n; i++){
            vector<int> temp(m);
            for(int j = 0; j<m; j++){
                int st,ld,rd;
                st = ld = rd = matrix[i][j];
                st += dp[j];
                if(j>0) ld += dp[j-1];
                else ld += 1e9;
                if(j+1<m) rd += dp[j+1];
                else rd += 1e9;
                temp[j] = min(st,min(ld,rd));
            }
            dp = temp;
        }
        for(int j = 0; j<m; j++) ans = min(ans,dp[j]);
        return ans;
    }
};