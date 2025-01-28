class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int[] prefProd = new int[n];
        int[] suffProd = new int[n];
        prefProd[0] = 1;
        suffProd[n-1] = 1;
        for(int i = 1; i<n; i++){
            prefProd[i] = prefProd[i-1]*nums[i-1];
        }
        for(int i = n-2; i>=0; i--){
            suffProd[i] = suffProd[i+1]*nums[i+1];
        }
        for(int i = 0; i<n; i++){
            ans[i] = prefProd[i]*suffProd[i];
        }
        return ans;
    }
}