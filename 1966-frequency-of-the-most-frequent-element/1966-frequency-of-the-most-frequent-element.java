class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int left = 0;
        long sum = 0;
        for(int right = 0; right<nums.length; right++){
            long target = nums[right];
            sum += target;
            if((right-left+1)*target-sum>k){
                sum -= nums[left];
                left++;
            }
        }
        return nums.length-left;
    }
}