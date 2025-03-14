class Solution {
    public boolean canDist(int[] candies, int allowed, long children){
        if(allowed == 0) return false;
        long satisfied = 0;
        for(int candy : candies){
            satisfied += candy/allowed;
            if(satisfied>=children) return true;
        }
        return false;
    }
    public int maximumCandies(int[] candies, long k) {
        int left = 1, right = 0, result = 0;
        for(int candy : candies) right = Math.max(candy,right);
        while(left<=right){
            int mid = left+(right-left)/2;
            if(canDist(candies,mid,k)){
                result = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        return result;
    }
}