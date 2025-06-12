class Solution {
    private void dfs(int row, int col, int n, int m, int[] dRow, int[] dCol, int[][] vis, int[][] grid){
        vis[row][col] = 1;
        for(int i = 0; i<4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if((nRow<n && nRow>=0) && (nCol<m && nCol>=0) && (vis[nRow][nCol]==0 && grid[nRow][nCol]==1)) dfs(nRow,nCol,n,m,dRow,dCol,vis,grid);
        }
    }
    public int numEnclaves(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] vis = new int[n][m];
        int[] dRow = {-1,0,1,0};
        int[] dCol = {0,1,0,-1};
        for(int i = 0; i<n; i++){
            if(vis[i][0] == 0 && grid[i][0] == 1) dfs(i,0,n,m,dRow,dCol,vis,grid);
            if(vis[i][m-1] == 0 && grid[i][m-1] == 1) dfs(i,m-1,n,m,dRow,dCol,vis,grid);
        }
        for(int i = 0; i<m; i++){
            if(vis[0][i] == 0 && grid[0][i] == 1) dfs(0,i,n,m,dRow,dCol,vis,grid);
            if(vis[n-1][i] == 0 && grid[n-1][i] == 1) dfs(n-1,i,n,m,dRow,dCol,vis,grid);
        }
        int enclaves = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) enclaves++;
            }
        }
        return enclaves;
    }
}