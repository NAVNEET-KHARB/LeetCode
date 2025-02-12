class Solution {
    public int maximumSum(int[] nums) {
        int[] sum = new int[82];
        int ans = -1;
        for(int num : nums){
            int dSum = 0;
            int curr = num;
            while(curr>0){
                dSum += curr%10;
                curr /= 10;
            }
            if(sum[dSum]!=0) ans = Math.max(ans,sum[dSum]+num);
            sum[dSum] = Math.max(sum[dSum],num);
        }
        return ans;
    }
}