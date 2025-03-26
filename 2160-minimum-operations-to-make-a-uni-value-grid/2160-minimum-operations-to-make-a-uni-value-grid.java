class Solution {
    public int minOperations(int[][] grid, int x) {
        int n = grid.length, m = grid[0].length;
        int[] arr = new int[m*n];
        int rem = grid[0][0]%x;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]%x != rem) return -1;
                arr[i*m+j] = grid[i][j];
            }
        }
        Arrays.sort(arr);
        int sz = m*n;
        int median = arr[sz/2];
        int operations = 0;
        for(int i = 0; i<sz; i++){
            operations += Math.abs(median-arr[i])/x;
        }
        return operations;
    }
}