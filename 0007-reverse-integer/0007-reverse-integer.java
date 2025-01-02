class Solution {
    public int reverse(int x) {
        long ans = 0;
        int temp = x;
        while(temp!=0){
            int digit = temp%10;
            ans = ans*10 + digit;
            temp /= 10;
        }
        if(ans > Integer.MAX_VALUE || ans<Integer.MIN_VALUE) return 0;
        return (int)ans;
    }
}