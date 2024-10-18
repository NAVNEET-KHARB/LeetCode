class Solution {
    int solve(int ind, int currOR, int maxOR, vector<int> &nums, vector<vector<int>> &dp){
        if(ind == 0) return (currOR == maxOR)?1:0;
        if(dp[ind][currOR] != -1) return dp[ind][currOR];
        int notTake = solve(ind-1,currOR,maxOR,nums,dp);
        int take = solve(ind-1,currOR|nums[ind-1],maxOR,nums,dp);
        return dp[ind][currOR] = take + notTake;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;
        for(int num : nums) maxOR |= num;
        vector<vector<int>> dp(n+1,vector<int>(maxOR+1,-1));
        return solve(n,0,maxOR,nums,dp);
    }
};