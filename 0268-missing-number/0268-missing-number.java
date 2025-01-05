class Solution {
    public int missingNumber(int[] nums) {
        int xorr1= 0;
        int xorr2= 0;
        for(int i = 1; i<=nums.length; i++){
            xorr1 ^= i;
        }
        for(int num : nums){
            xorr2 ^= num;
        }
        return xorr1^xorr2;
    }
}