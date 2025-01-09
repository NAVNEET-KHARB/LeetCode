class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int sum = 0, ans = 0;
        HashMap<Integer,Integer> preMap = new HashMap<>();
        preMap.put(0,1);
        for(int i = 0; i<n; i++){
            sum += nums[i];
            int req = sum-k;
            if(preMap.containsKey(req)){
                ans += preMap.get(req);
            }
            preMap.put(sum, preMap.getOrDefault(sum,0)+1);
        }
        return ans;
    }
}