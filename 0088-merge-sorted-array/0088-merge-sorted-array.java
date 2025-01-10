class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if(n==0) return;
        if(m == 0){
            int i = 0;
            for(int num : nums2){
                nums1[i] = num;
                i++;
            }
        }
        int i = m-1;
        int j  = n-1;
        int k = m+n-1;
        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }else{
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
    }
}