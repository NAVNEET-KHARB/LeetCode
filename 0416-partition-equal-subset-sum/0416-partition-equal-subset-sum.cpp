class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++) sum += nums[i];
        if(sum&1) return false;
        int target = sum/2;
        vector<bool> dp(target+1,false);
        vector<bool> temp(target+1,false);
        dp[0] = temp[0] = true;
        if(nums[0]<=target) dp[nums[0]] = true;
        for(int i = 1; i<n; i++){
            for(int j = 1; j<=target; j++){
                bool notTake = dp[j];
                bool take = false;
                if(j>=nums[i]) take = dp[j-nums[i]];
                temp[j] = take | notTake;
            }
            dp = temp;
        }
        return dp[target];
    }
};