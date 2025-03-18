class Solution {
    public int longestNiceSubarray(int[] nums) {
        int n = nums.length;
        int left = 0, right = 0;
        int currL = 0, andNum = 0, ans = 0;
        while(right<n){
            while((andNum & nums[right])!= 0){
                andNum ^= nums[left++];
            }
            andNum |= nums[right];
            ans = Math.max(ans,right-left+1);
            right++;
        }
        return ans;
    }
}