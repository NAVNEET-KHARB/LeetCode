class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int ans = Integer.MIN_VALUE;
        int prodF = 1;
        int prodB = 1;
        for(int i = 0; i<n; i++){
            if(prodF == 0) prodF = 1;
            if(prodB == 0) prodB = 1;
            prodF *= nums[i];
            prodB *= nums[n-i-1];
            ans = Math.max(ans,Math.max(prodF,prodB));
        }
        return ans;
    }
}