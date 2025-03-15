class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        Deque<Integer> dq = new LinkedList<>();
        int[] ans = new int[n-k+1];
        int ansInd = 0;
        for(int i = 0; i<n; i++){
            if(!dq.isEmpty() && dq.getFirst() <= i-k) dq.pollFirst();
            while(!dq.isEmpty() && nums[dq.getLast()]<=nums[i]) dq.pollLast();
            dq.add(i);
            if(i>=k-1) ans[ansInd++] = nums[dq.getFirst()];
        }
        return ans;
    }
}