class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        long ans = 0;
        int[] left = new int[n];
        int[] right = new int[n];
        for(int i = 1; i<n; i++){
            left[i] = Math.max(left[i-1],nums[i-1]);
            right[n-i-1] = Math.max(nums[n-i],right[n-i]);
        }
        for(int j = 1; j<n-1; j++){
            ans = Math.max(ans,(long)(left[j]-nums[j])*right[j]);
        }
        return ans;
    }
}