class Solution {
    public int countSubarrays(int[] nums) {
        int cnt = 0, n = nums.length;
        Deque<Integer> dq = new ArrayDeque<>();
        for(int i = 0; i<n; i++){
            dq.addLast(nums[i]);
            if(dq.size() == 3){
                int sum = dq.peekFirst() + dq.peekLast();
                dq.pollFirst();
                if((double)sum == dq.peekFirst()/2.0) cnt++;
            }
        }
        return cnt;
    }
}