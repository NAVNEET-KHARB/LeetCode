class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int zInd = -1;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                zInd = i;
                break;
            }
        }
        if(zInd == -1) return;
        for(int i = zInd+1; i<n; i++){
            if(nums[i]!=0){
                int temp = nums[i];
                nums[i] = nums[zInd];
                nums[zInd] = temp;
                zInd++;
            }
        }
    }
}