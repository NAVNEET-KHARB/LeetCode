class Solution {
    public boolean distPoss(int[]position, int dist, int totalBalls){
        int balls = 1;
        int lastPos = position[0];
        for(int i = 1; i<position.length; i++){
            if(position[i]-lastPos>=dist){
                balls++;
                lastPos = position[i];
            }
            if(balls==totalBalls) return true;
        }
        return false;
    }
    public int maxDistance(int[] position, int m) {
        int n = position.length;
        Arrays.sort(position);
        int low = 0, high = position[n-1]-position[0];
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(distPoss(position,mid,m)){
                ans = mid;
                low = mid+1;
            }else high = mid-1;
        }
        return ans;
    }
}