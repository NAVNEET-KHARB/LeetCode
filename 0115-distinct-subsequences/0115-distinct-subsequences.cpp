class Solution {
    long long solve(int i, int j, string &s, string &t, vector<vector<long long>> &dp){
        if(j==0) return 1;
        if(i==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]) return dp[i][j] = solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
        return dp[i][j] = solve(i-1,j,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));
        solve(n,m,s,t,dp);
        return (dp[n][m]>INT_MAX)?-1:(int)dp[n][m];
    }
};