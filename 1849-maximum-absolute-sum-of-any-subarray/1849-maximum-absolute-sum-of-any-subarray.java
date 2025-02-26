class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int minPSum = 0, maxPSum = 0;
        int pSum = 0;
        for(int i = 0; i<nums.length; i++){
            pSum += nums[i];
            minPSum = Math.min(minPSum,pSum);
            maxPSum = Math.max(maxPSum,pSum);
        }
        return maxPSum-minPSum;
    }
}