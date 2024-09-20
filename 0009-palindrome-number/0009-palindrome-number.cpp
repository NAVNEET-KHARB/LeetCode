class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long rx = 0;
        int temp = x;
        while(temp){
            rx = rx*10 + temp%10;
            temp /= 10; 
        }
        return x==rx;
    }
};