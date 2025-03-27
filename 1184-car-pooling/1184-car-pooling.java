class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int n = trips.length;
        int[] dist = new int[1002];
        for(int i = 0; i<n; i++){
            dist[trips[i][1]] += trips[i][0];
            dist[trips[i][2]] -= trips[i][0];
        }
        int currPassengers = 0;
        for(int i = 0; i<1002; i++){
            currPassengers += dist[i];
            if(currPassengers>capacity) return false;
        }
        return true;
    }
}