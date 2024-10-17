class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        const long long MOD = 1e9 + 7;
        vector<long long> dp(m+1,0);
        vector<long long> temp(m+1,0);
        dp[0] = temp[0] = 1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1]==t[j-1]) temp[j] = (dp[j-1] + dp[j])%MOD;
                else temp[j] = dp[j];
            }
            dp = temp;
        }
        return (int)dp[m];
    }
};