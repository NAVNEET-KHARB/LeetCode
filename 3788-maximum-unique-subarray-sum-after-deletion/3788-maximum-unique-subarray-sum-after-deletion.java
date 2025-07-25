class Solution {
    public int maxSum(int[] nums) {
        int n = nums.length;
        HashMap<Integer,Integer> mpp = new HashMap<>();
        int ans = 0, maxEle = Integer.MIN_VALUE;
        for(int i = 0; i<n; i++){
            maxEle = Math.max(maxEle,nums[i]);
            if(mpp.containsKey(nums[i]) || nums[i]<0) continue;
            else{
                ans += nums[i];
                mpp.put(nums[i],1);
            }
        }
        return (maxEle<0)?maxEle:ans;
    }
}