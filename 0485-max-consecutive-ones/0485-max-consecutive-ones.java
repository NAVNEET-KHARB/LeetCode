class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans = 0;
        int curr = 0;
        for(int num : nums){
            if(num == 0){
                if(curr>ans) ans = curr;
                curr = 0;
            }else curr++;
        }
        if(curr>ans) ans = curr;
        return ans;
    }
}