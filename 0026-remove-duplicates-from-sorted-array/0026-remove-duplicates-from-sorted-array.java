class Solution {
    public int removeDuplicates(int[] nums) {
        int sInd = 0;
        for(int i = 1; i<nums.length; i++){
            if(nums[i]!=nums[sInd]){
                nums[sInd+1] = nums[i];
                sInd++;
            }
        }
        return sInd+1;
    }
}