class Solution {
    public double myPow(double x, int n) {
        double ans = 1;
        long N = n;
        boolean neg = false;
        if(n<0){
            neg = true;
            N *= -1;
        }
        while(N>0){
            if(N%2==0){
                x *= x;
                N /= 2;
            }else{
                ans *= x;
                N--;
            }
        }
        return neg?1/ans:ans;
    }
}