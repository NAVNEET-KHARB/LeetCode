class Solution {
    public int searchInsert(int[] nums, int target) {
        int n = nums.length;
        int left = 0, right = n-1;
        int ans = -1;
        boolean flag = false;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]<=target){
                if(nums[mid] == target) flag = true;
                ans = mid;
                left = mid+1;
            }else right = mid-1;
        }
        return flag?ans:ans+1;
    }
}