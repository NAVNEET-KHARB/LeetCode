class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        int left = 0, curr = 0, ans = 0;
        HashSet<Integer> set = new HashSet<>();
        for (int right = 0; right < n; right++) {
            while (set.contains(nums[right])) {
                set.remove(nums[left]);
                curr -= nums[left];
                left++;
            }
            set.add(nums[right]);
            curr += nums[right];
            ans = Math.max(ans, curr);
        }
        return ans;
    }
}
