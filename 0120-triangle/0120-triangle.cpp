class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n,-1);
        for(int j = 0; j<n; j++) dp[j] = triangle[n-1][j];
        for(int i = n-2; i>=0; i--){
            vector<int> temp(n);
            for(int j = i; j>=0; j--){
                int down = triangle[i][j] + dp[j];
                int diagonal = triangle[i][j] + dp[j+1];
                temp[j] = min(down,diagonal);
            }
            dp = temp;
        }
        return dp[0];
    }
};