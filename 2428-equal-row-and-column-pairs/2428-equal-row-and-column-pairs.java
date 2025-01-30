class Solution {
    public int equalPairs(int[][] grid) {
        int [][] arr = new int[grid.length][grid.length];
        int count = 0;
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid.length; j++) arr[j][i] = grid[i][j];
        }
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid.length; j++) {
                if(Arrays.equals(arr[j],grid[i])) count++;
            }
        }
        return count;
    }
}