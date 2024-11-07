class Solution {
    int solve(int day, int tar, int curr, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore, vector<vector<int>>& dp){
        if(day == tar) return 0;
        if(dp[day][curr] != -1) return dp[day][curr];
        int maxPoints = stayScore[day][curr] + solve(day+1,tar,curr,stayScore,travelScore,dp);
        for(int dest = 0; dest<travelScore.size(); dest++){
            if(dest != curr) maxPoints = max(maxPoints, travelScore[curr][dest] + solve(day+1, tar,dest,stayScore,travelScore,dp));
        }
        return dp[day][curr] = maxPoints;
    }
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<vector<int>> dp(k,vector<int>(n,-1));
        int ans = 0;
        for(int st = 0; st<n; st++){
            ans = max(ans,solve(0,k,st,stayScore,travelScore,dp));
        }
        return ans;
    }
};