class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        int temp = 0;
        for(int i = 0; i<nums.length; i++){
            if(temp+nums[i] == sum) return i;
            temp += nums[i];
            sum -= nums[i];
        }
        return -1;
    }
}