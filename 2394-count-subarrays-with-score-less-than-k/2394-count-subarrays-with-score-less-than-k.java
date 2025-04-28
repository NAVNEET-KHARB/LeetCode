class Solution {
    public long countSubarrays(int[] nums, long k) {
        int n = nums.length;
        int left = 0, right = 0;
        long ans = 0, sum = 0;
        while(right<n){
            sum += nums[right];
            while(left<=right && sum*(right-left+1) >= k){
                sum -= nums[left];
                left++;
            }
            ans += right-left+1;
            right++;
        }
        return ans;
    }
}