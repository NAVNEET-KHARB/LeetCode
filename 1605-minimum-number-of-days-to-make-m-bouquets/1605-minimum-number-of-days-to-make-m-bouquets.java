class Solution {
    public boolean boquetsPoss(int[] bloomDay, int day, int boquetsR, int flowers){
        int consFlowers = 0;
        int boquets = 0;
        for(int bloom : bloomDay){
            if(bloom<=day) consFlowers++;
            else{
                boquets += (consFlowers/flowers);
                consFlowers = 0;
            }
        }
        boquets += (consFlowers/flowers);
        return boquets>=boquetsR;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        int low = 1, high = -1;
        for(int day : bloomDay) high = Math.max(high,day);
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(boquetsPoss(bloomDay,mid,m,k)){
                high = mid-1;
                ans = mid;
            }else low = mid+1;
        }
        return ans;
    }
}