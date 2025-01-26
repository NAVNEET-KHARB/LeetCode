class Solution {
    public boolean divPoss(int[]nums, int divisor, int threshold){
        long divResults = 0;
        for(int num : nums){
            divResults += (long)(num/divisor) + (num%divisor == 0?0:1);
            if(divResults>threshold) return false;
        }
        return true;
    }
    public int smallestDivisor(int[] nums, int threshold) {
        int low = 1, high = -1;
        for(int num : nums) high = Math.max(high,num);
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(divPoss(nums,mid,threshold)){
                ans = mid;
                high = mid-1;
            }else low = mid+1;
        }
        return ans;
    }
}