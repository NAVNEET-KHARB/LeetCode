class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int i = 1; i<=n; i++) dp[i][0] = false;
        for(int j = 1; j<=m; j++){
            if(p[j-1] == '*' && j>=2) dp[0][j] = dp[0][j-2];
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*'){
                    bool notTake = dp[i][j-2];
                    bool take = (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];
                    dp[i][j] = take||notTake;
                }
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};