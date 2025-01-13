class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = new int[]{-1,-1};
        int n = nums.length;
        int lowF = 0, highF = n-1;
        int lowL = 0, highL = n-1;
        while(lowL<=highL || lowF<=highF){
            int midL = lowL+(highL-lowL)/2;
            if(nums[midL]<=target){
                if(nums[midL] == target) ans[1] = midL;
                lowL = midL+1;
            }else highL = midL-1;
            int midF = lowF+(highF-lowF)/2;
            if(nums[midF]>=target){
                if(nums[midF] == target) ans[0] = midF;
                highF = midF-1;
            }else lowF = midF+1;
        }
        return ans;
    }
}