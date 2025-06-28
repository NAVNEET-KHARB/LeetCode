class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int n = nums.length;
        int[][] vals = new int[n][2];
        for(int i = 0; i<n; i++){
            vals[i][0] = i;
            vals[i][1] = nums[i];
        }
        Arrays.sort(vals, (a,b)->{ return b[1]-a[1];});
        Arrays.sort(vals, 0, k ,(a,b)->{ return a[0]-b[0];});
        int[] subs = new int[k];
        for(int i = 0; i<k; i++){
            subs[i] = vals[i][1];
        }
        return subs;
    }
}