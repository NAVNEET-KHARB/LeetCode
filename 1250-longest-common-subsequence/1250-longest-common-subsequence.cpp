class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<int> dp(m+1,0);
        vector<int> temp(m+1,0);
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(text1[i-1] == text2[j-1]) temp[j] = 1 + dp[j-1];
                else temp[j] = max(temp[j-1],dp[j]);
            }
            dp = temp;
        }
        return dp[m];
    }
};