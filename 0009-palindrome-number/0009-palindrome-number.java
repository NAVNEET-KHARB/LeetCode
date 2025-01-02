class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) return false;
        int rn = 0;
        int temp = x;
        while (temp !=0) {
            rn = rn * 10 + temp % 10;
            temp /= 10;
        }
        if (x == rn)
            return true;
        return false;
    }
}