class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<bool> dp(m+1,false);
        vector<bool> temp(m+1,false);
        dp[0] = true;
        for(int j = 1; j<=m; j++){
            if(p[j-1] == '*' && j>=2) dp[j] = dp[j-2];
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.') temp[j] = dp[j-1];
                else if(p[j-1] == '*'){
                    bool notTake = temp[j-2];
                    bool take = (s[i-1] == p[j-2] || p[j-2] == '.') && dp[j];
                    temp[j] = take||notTake;
                }
                else temp[j] = false;
            }
            dp = temp;
        }
        return dp[m];
    }
};