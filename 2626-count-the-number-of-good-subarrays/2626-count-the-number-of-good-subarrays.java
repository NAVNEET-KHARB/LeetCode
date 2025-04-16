class Solution {
    public long countGood(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer,Integer> mpp = new HashMap<>();
        int pairs = 0, left = 0, right = 0;
        long ans = 0;
        while(left<n){
            while(pairs<k && right<n){
                pairs += mpp.getOrDefault(nums[right],0);
                mpp.put(nums[right],mpp.getOrDefault(nums[right],0)+1);
                right++;
            }
            if(pairs>=k) ans += n-right+1;
            mpp.put(nums[left],mpp.get(nums[left])-1);
            pairs -= mpp.get(nums[left]);
            left++;
        }
        return ans;
    }
}