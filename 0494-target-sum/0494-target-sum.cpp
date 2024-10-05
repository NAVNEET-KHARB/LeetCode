class Solution {
    int countWays(int target, vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        if(nums[0]==0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(nums[0]!=0 && nums[0]<=target) dp[0][nums[0]] = 1;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<=target; j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(nums[i]<=j) take = dp[i-1][j-nums[i]];
                dp[i][j] = take+notTake;
            }
        }
        return dp[n-1][target];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum = 0;
        for(int num: nums) totSum += num;
        if(totSum-target<0 || (totSum-target)%2) return 0;
        return countWays((totSum-target)/2,nums);
    }
};