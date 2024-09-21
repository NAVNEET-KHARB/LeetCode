class Solution {
    int solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return 1;
        if(dp[ind][target] != -1) return dp[ind][target];
        if(ind == 0) return dp[ind][target] = (nums[0] == target);
        int notTake = solve(ind-1,target,nums,dp);
        int take = 0;
        if(target>=nums[ind]) take = solve(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target] = take | notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++) sum += nums[i];
        if(sum&1) return false;
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);
    }
};