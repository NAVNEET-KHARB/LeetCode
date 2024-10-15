class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string rs(s.begin(),s.end());
        reverse(rs.begin(),rs.end());
        vector<int> dp(n+1,0);
        vector<int> temp(n+1,0);
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(s[i-1] == rs[j-1]) temp[j] = 1 + dp[j-1];
                else temp[j] = max(dp[j],temp[j-1]);
            }
            dp = temp;
        }
        return dp[n];
    }
};