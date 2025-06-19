class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int min = nums[0], max = 0;
        int subseq = 0;
        for(int i = 0; i<nums.length; i++){
            max = nums[i];
            if(max-min>k){
                subseq++;
                min = nums[i];
                max = nums[i];
            }
        }
        subseq++;
        return subseq;
    }
}