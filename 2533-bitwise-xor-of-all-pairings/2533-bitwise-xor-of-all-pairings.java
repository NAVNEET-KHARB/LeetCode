class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int xorr1 = 0, xorr2 = 0;
        int n1 = nums1.length;
        int n2 = nums2.length;
        if(n2%2 == 1){
            for(int num : nums1) xorr1 ^= num;
        }
        if(n1%2 == 1){
            for(int num : nums2) xorr2 ^= num;
        }
        return xorr1^xorr2;
    }
}