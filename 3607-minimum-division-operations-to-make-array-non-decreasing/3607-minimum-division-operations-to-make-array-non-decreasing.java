class Solution {
    public int minOperations(int[] nums) {
        int ans = 0;
        int n = nums.length;
        for(int i = n-2; i>=0; i--){
            if(nums[i]>nums[i+1]){
                for(int j = 2; j*j<=nums[i]; j++){
                    if(nums[i]%j==0){
                        nums[i] = j;
                        ans++;
                        break;
                    }
                }
                if(nums[i]>nums[i+1]) return -1;
            }
        }
        return ans;
    }
}