class Solution {
    public int countSubarrays(int[] nums) {
        int cnt = 0, n = nums.length;
        for(int i = 1; i<n-1; i++){
            if(nums[i] == (nums[i-1] + nums[i+1])*2) cnt++;
        }
        return cnt;
    }
}