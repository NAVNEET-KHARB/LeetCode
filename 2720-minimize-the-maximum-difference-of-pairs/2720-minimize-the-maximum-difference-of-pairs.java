class Solution {
    private boolean pPairsPoss(int[] nums, int diff, int p){
        int pairs = 0;
        for(int i = 1; i<nums.length; i++){
            if((nums[i]-nums[i-1]) <= diff){
                i++;
                pairs++;
            }
            if(pairs == p) return true;
        }
        return false;
    }
    public int minimizeMax(int[] nums, int p) {
        int n = nums.length;
        Arrays.sort(nums);
        int low = 0, high = nums[n-1]-nums[0];
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(pPairsPoss(nums,mid,p)){
                high = mid-1;
                ans = mid;
            }else low = mid+1;
        }
        return ans;
    }
}