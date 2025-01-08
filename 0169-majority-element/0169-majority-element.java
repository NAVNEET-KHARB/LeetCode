class Solution {
    public int majorityElement(int[] nums) {
        // Moore's Voting Algo
        int cnt = 0;
        int el = -1;
        for(int i = 0; i<nums.length; i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }else if(el == nums[i]) cnt++;
            else cnt--;
        }
        return el;
    }
}