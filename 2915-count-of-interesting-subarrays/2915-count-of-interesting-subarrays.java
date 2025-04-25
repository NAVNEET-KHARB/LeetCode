class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
        int n = nums.size();
        HashMap<Integer,Integer> mpp = new HashMap<>();
        long ans = 0;
        int prefix = 0;
        mpp.put(0,1);
        for(int i = 0; i<n; i++){
            prefix += nums.get(i)%modulo == k?1:0;
            ans += mpp.getOrDefault((prefix-k+modulo)%modulo,0);
            mpp.put(prefix%modulo,mpp.getOrDefault(prefix%modulo,0)+1);
        }
        return ans;
    }
}