class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length;
        int ans = 0;
        int[][] dp = new int[n][n];
        for(int curr = 2; curr<n; curr++){
            int start = 0;
            int end = curr-1;
            while(start<end){
                int sum = arr[start]+arr[end];
                if(sum>arr[curr]) end--;
                else if(sum<arr[curr]) start++;
                else{
                    dp[end][curr] = dp[start][end]+1;
                    ans = Math.max(ans,dp[end][curr]);
                    start++;
                    end--;
                }
            }
        }
        return ans==0?0:ans+2;
    }
}