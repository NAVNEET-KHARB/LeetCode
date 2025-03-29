class Solution {
    public boolean repPoss(int[] ranks, int cars, long time){
        long carsRep = 0;
        for(int rank : ranks){
            long carsR = time/rank;
            carsRep += (long)Math.sqrt(carsR);
            if(carsRep>=cars) return true;
        }
        return false;
    }
    public long repairCars(int[] ranks, int cars) {
        long left = 1, right = 0, maxRank = 0, ans = 0;
        for(int rank : ranks) maxRank = Math.max(rank,maxRank);
        right = (maxRank*((long)cars*cars));
        while(left<=right){
            long mid = left+(right-left)/2;
            if(repPoss(ranks,cars,mid)){
                ans = mid;
                right = mid-1;
            }else left = mid+1;
        }
        return ans;
    }
}