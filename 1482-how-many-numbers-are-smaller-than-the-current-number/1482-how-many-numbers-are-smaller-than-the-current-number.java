class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int n = nums.length;
        int[] count = new int[101];
        int[] ans = new int[n];
        for(int i = 0; i<n; i++) count[nums[i]]++;
        for(int i = 1; i<=100; i++) count[i] += count[i-1];
        for(int i =0; i<n; i++){
            if(nums[i] == 0) ans[i] = 0;
            else ans[i] = count[nums[i]-1];
        }
        return ans;
    }
}