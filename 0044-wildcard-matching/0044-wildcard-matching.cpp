class Solution {
    bool isAllStars(string& S1, int i) {
        for (int j = 1; j <= i; j++) {
            if (S1[j - 1] != '*')
                return false;
        }
        return true;
    }

public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<bool> dp(m + 1, false);
        vector<bool> temp(m + 1, false);
        dp[0] = true;
        for (int j = 1; j <= m; j++) {
            dp[j] = isAllStars(p, j);
        }
        for (int i = 1; i <= n; i++) {
            temp[0] = false;
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    temp[j] = dp[j - 1];
                else if (p[j - 1] == '*')
                    temp[j] = (dp[j] || temp[j - 1]);
                else
                    temp[j] = false;
            }
            dp = temp;
        }
        return dp[m];
    }
};