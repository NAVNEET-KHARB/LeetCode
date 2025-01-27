class Solution {
    public boolean distPoss(int[] quantities, int limit, int totShops){
        int shops = 0;
        for(int quantity : quantities){
            shops += (quantity/limit) + (quantity%limit==0?0:1);
            if(shops>totShops) return false;
        }
        return true;
    }
    public int minimizedMaximum(int n, int[] quantities) {
        int low = 1, high = 0;
        for(int quant : quantities){
            high = Math.max(high,quant);
        }
        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(distPoss(quantities,mid,n)){
                ans = mid;
                high = mid-1;
            }else low = mid+1;
        }
        return ans;
    }
}