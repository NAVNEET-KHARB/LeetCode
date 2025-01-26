class Solution {
    public long hours(int[] piles, int rate){
        long hrsTaken = 0;
        for(int banana : piles){
            hrsTaken += (long)(banana/rate) + (banana%rate==0?0:1);
        }
        return hrsTaken;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int low = 1;
        int high = -1;
        for(int ban : piles) high = Math.max(high,ban);
        long ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            long hrsTaken = hours(piles,mid);
            if(hrsTaken<=h){
                high = mid-1;
                if(mid<ans) ans = mid;
            }else low = mid+1;
        }
        return (int)ans;
    }
}