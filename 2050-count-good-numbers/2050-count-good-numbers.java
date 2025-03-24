class Solution {
    public long myPow(long x, long n) {
        long ans = 1;
        int mod = (int)(1e9+7);
        while(n>0){
            if(n%2==1){
                ans = (ans*x)%mod;
            }
            x = (x*x)%mod;
            n /= 2;
        }
        return ans%mod;
    }
    public int countGoodNumbers(long n) {
        int mod = (int)(1e9+7);
        long ans = myPow(20,n/2);
        if(n%2 == 1){
            ans = (ans*5%mod);
        }
        return (int)ans;
    }
}