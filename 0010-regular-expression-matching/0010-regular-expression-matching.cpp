class Solution {
    int solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;
        if(i>0 && j==0) return 0;
        if(i == 0 && j>0){
            if(p[j-1] == '*') return solve(i,j-2,s,p,dp);
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1] == p[j-1] || p[j-1] == '.') return dp[i][j] = solve(i-1,j-1,s,p,dp);
        else if(p[j-1] == '*'){
            bool notTake = solve(i,j-2,s,p,dp);
            bool take = (s[i-1] == p[j-2] || p[j-2] == '.') && solve(i-1, j, s, p, dp);
            return dp[i][j] = take||notTake;
        }
        return dp[i][j] = 0;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,s,p,dp);
    }
};