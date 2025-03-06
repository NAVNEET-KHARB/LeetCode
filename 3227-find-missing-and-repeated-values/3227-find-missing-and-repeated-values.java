class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int[] hash = new int[(n*n)+1];
        int[] ans = new int[2];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<grid[i].length; j++){
                if(hash[grid[i][j]] == 1) ans[0] = grid[i][j];
                else hash[grid[i][j]]++;
            }
        }
        for(int i = 1; i<=n*n; i++){
            if(hash[i] == 0) ans[1] = i;
        }
        return ans;
    }
}