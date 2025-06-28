class Solution {
    public int[] findIntersectionValues(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        int[][] pairs = new int[101][2];
        int i = 0, j = 0;
        while(i<n || j<m){
            if(i<n) pairs[nums1[i++]][0]++;
            if(j<m) pairs[nums2[j++]][1]++;
        }
        int[] ans = new int[2];
        for(int k = 0; k<=100; k++){
            if(pairs[k][0]>0 && pairs[k][1]>0){
                ans[0] += pairs[k][0];
                ans[1] += pairs[k][1];
            }
        }
        return ans;
    }
}