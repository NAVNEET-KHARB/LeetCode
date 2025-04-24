class Solution {
    public int countCompleteSubarrays(int[] nums) {
        int n = nums.length;
        HashSet<Integer> set = new HashSet<>();
        for(int num : nums) set.add(num);
        HashMap<Integer,Integer> mpp = new HashMap<>();
        int left = 0, right = 0, ans = 0, el = 0;
        while(right<n){
            if(!mpp.containsKey(nums[right])){
                el++;
            }
            mpp.put(nums[right],mpp.getOrDefault(nums[right],0)+1);
            while(el == set.size()){
                ans += n-right;
                mpp.put(nums[left],mpp.getOrDefault(nums[left],0)-1);
                if(mpp.get(nums[left]) == 0){
                    el--;
                    mpp.remove(nums[left]);
                }
                left++;
            }
            right++;
        }
        return ans;
    }
}