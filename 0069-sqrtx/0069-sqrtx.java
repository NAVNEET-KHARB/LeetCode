class Solution {
    public int mySqrt(int x) {
        long low = 1;
        long high = x;
        int ans = 0;
        while(low<=high){
            long mid = low+(high-low)/2;
            long mul = mid*mid;
            if(mul == x) return (int)mid;
            else if(mul<x){
                ans = (int)mid;
                low = mid+1;
            }else high = mid-1;
        }
        return ans;
    }
}