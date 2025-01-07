class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        int[] ans = new int[2];
        HashMap<Integer,Integer> mpp = new HashMap<>();
        for(int i = 0; i<n; i++){
            int curr = nums[i];
            int rem = target-curr;
            if(mpp.containsKey(rem)){
                ans[0] = mpp.get(rem);
                ans[1] = i;
                return ans;
            }
            mpp.put(curr,i);
        }
        return ans;
    }
}