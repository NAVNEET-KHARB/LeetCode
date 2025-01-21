class Solution {
    public long gridGame(int[][] grid) {
        long fRSum = 0;
        for(int num : grid[0]){
            fRSum += num;
        }
        long sRSum = 0;
        long minSum = Long.MAX_VALUE;
        for(int i = 0; i<grid[0].length; i++){
            fRSum -= grid[0][i];
            minSum = Math.min(minSum,Math.max(fRSum,sRSum));
            sRSum += grid[1][i];
        }
        return minSum;
    }
}