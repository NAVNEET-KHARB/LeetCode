class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        long ans = 0, iVal = 0, diffVal = 0;
        for(int k = 0; k<n; k++){
            ans = Math.max(ans,(long)nums[k]*diffVal);
            diffVal = Math.max(diffVal,iVal-nums[k]);
            iVal = Math.max(iVal,nums[k]);
        }
        return ans;
    }
}