class Solution {
    public long countSubarrays(int[] nums, int k) {
        int n = nums.length, maxEle = 0;
        for(int i = 0; i<n; i++){
            maxEle = Math.max(maxEle,nums[i]);
        }
        long ans = 0; 
        int cnt = 0, left = 0, right = 0;
        while(right<n){
            if(nums[right] == maxEle) cnt++;
            while(left<=right && cnt==k){
                ans += n-right;
                if(nums[left] == maxEle) cnt--;
                left++;
            }
            right++;
        }
        return ans;
    }
}