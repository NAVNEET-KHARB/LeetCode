class Solution {
    public int numOfSubarrays(int[] arr) {
        final int mod = 1_000_000_007;
        int ans = 0, sum = 0;
        int odd = 0, even = 1;
        for(int num : arr){
            sum += num;
            if(sum%2==0){
                ans += odd;
                even++;
            }else{
                ans += even;
                odd++;
            }
            ans %= mod;
        }
        return ans;
    }
}