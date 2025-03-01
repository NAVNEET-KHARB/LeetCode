class Solution {
    public int[] applyOperations(int[] nums) {
        int n = nums.length;
        for(int i = 0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        int fZ = 0;
        while(fZ<n && nums[fZ]!=0) fZ++;
        for(int i = fZ+1; i<n; i++){
            if(nums[i]!=0){
                nums[fZ++] = nums[i];
                nums[i] = 0;
            }
        }
        return nums;
    }
}