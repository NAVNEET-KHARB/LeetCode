class Solution {
    public int singleNumber(int[] nums) {
        int xorr = 0;
        for(int num : nums) xorr ^= num;
        return xorr;
    }
}