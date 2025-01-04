class Solution {
    public boolean check(int[] nums) {
        int sort = 0;
        for(int i = 0; i<nums.length-1; i++){
            if(nums[i]>nums[i+1]) sort++;
        }
        if(sort == 0) return true;
        if(sort == 1){
            if(nums[nums.length-1]<=nums[0]) return true;
        }
        return false;
    }
}