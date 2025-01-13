class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = new int[]{-1,-1};
        int n = nums.length;
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]<=target){
                if(nums[mid] == target) ans[1] = mid;
                low = mid+1;
            }else high = mid-1;
        }
        low = 0;
        high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]>=target){
                if(nums[mid] == target) ans[0] = mid;
                high = mid-1;
            }else low = mid+1;
        }
        return ans;
    }
}