class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        long sum = 0, sqrSum = 0;
        long total = (long)n*n;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                sum += grid[i][j];
                sqrSum += (long)grid[i][j]*grid[i][j];
            }
        }
        long sumDiff = sum - (total*(total+1))/2;
        long sqrDiff = sqrSum - (total*(total+1)*(2*total+1))/6;
        int repeat = (int)(sqrDiff/sumDiff+sumDiff)/2;
        int missing = (int)(sqrDiff/sumDiff-sumDiff)/2;
        return new int[]{repeat,missing};
    }
}