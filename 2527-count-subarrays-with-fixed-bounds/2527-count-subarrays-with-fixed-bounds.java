class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        int n = nums.length;
        int left = 0;
        long ans = 0;
        Deque<Integer> dqMin = new ArrayDeque<>();
        Deque<Integer> dqMax = new ArrayDeque<>();
        for(int i = 0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                dqMin.clear();
                dqMax.clear();
                left = i+1;
                continue;
            }
            while(!dqMin.isEmpty() && nums[dqMin.peekLast()]>=nums[i]) dqMin.pollLast();
            dqMin.addLast(i);
            while(!dqMax.isEmpty() && nums[dqMax.peekLast()]<=nums[i]) dqMax.pollLast();
            dqMax.addLast(i);
            if(nums[dqMin.peekFirst()] == minK && nums[dqMax.peekFirst()] == maxK){
                int start = Math.min(dqMin.peekFirst(),dqMax.peekFirst());
                ans += (start - left + 1);
            }
        }
        return ans;
    }
}