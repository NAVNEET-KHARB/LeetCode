class Solution {
    public boolean shippingPoss(int[]weights, int limit, int daysR){
        int weightComb = 0;
        int days = 1;
        for(int weight : weights){
            if(weightComb + weight > limit){
                days++;
                weightComb = weight;
            }else weightComb += weight;
            if(days>daysR) return false;
        }
        return true;
    }
    public int shipWithinDays(int[] weights, int days) {
        int low = -1, high = 0;
        for(int weight : weights){
            high += weight;
            low = Math.max(weight,low);
        }
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(shippingPoss(weights,mid,days)){
                ans = mid;
                high = mid-1;
            }else low = mid+1;
        }
        return ans;
    }
}