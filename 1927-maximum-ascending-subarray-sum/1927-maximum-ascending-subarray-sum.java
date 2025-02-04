class Solution {
    public int maxAscendingSum(int[] nums) {
        int maxS = 0;
        int currS = nums[0];
        int left = 1;
        while(left<nums.length){
            if(nums[left]<=nums[left-1]){
                maxS = Math.max(maxS,currS);
                currS = 0;
            }
            currS += nums[left];
            left++;
        }
        maxS = Math.max(maxS,currS);
        return maxS;
    }
}