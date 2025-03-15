class Solution {
    public boolean robPoss(int[] nums, int allowed, int k){
        int robbed = 0;
        for(int i = 0; i<nums.length; i++){
            if(nums[i]<=allowed){
                robbed++;
                i++;
            }
            if(robbed>=k) return true;
        }
        return false;
    }
    public int minCapability(int[] nums, int k) {
        int left = 1, right = 0, ans = 0;
        for(int num : nums) right = Math.max(right,num);
        while(left<=right){
            int mid = left + (right-left)/2;
            if(robPoss(nums,mid,k)){
                ans = mid;
                right = mid-1;
            }else left = mid+1;
        }
        return ans;
    }
}