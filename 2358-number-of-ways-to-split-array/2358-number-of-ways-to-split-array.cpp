class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long leftSum = 0,rightSum = 0;
        for(int num : nums){
            rightSum += num;
        }
        int ans = 0;
        for(int i = 0; i<nums.size()-1; i++){
            leftSum += nums[i];
            rightSum -= nums[i];
            if(leftSum>=rightSum) ans++;
        }
        return ans;
    }
};