class Solution {
    public long countBadPairs(int[] nums) {
        int n = nums.length;
        HashMap<Integer,Integer> mpp = new HashMap<>();
        long ans = 0;
        for(int i = 0; i<n; i++){
            int diff = i-nums[i];
            int pairs = mpp.getOrDefault(diff,0);
            ans += i-pairs;
            mpp.put(diff,pairs+1);
        }
        return ans;
    }
}