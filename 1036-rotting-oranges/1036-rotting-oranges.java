class Solution {
    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] vis = new int[n][m];
        Queue<int[]> q = new LinkedList<>();
        int time = 0, freshOranges = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.add(new int[]{i,j,0});
                    vis[i][j] = 1;
                }
                if(grid[i][j] == 1) freshOranges++;
            }
        }
        int oranges = 0;
        int[] dRow = {-1,0,1,0};
        int[] dCol = {0,1,0,-1};
        while(!q.isEmpty()){
            int[] rotten = q.poll();
            int row = rotten[0], col = rotten[1], t = rotten[2];
            time = Math.max(time,t);
            for(int i = 0; i<4; i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                if((nRow<n && nRow>=0) && (nCol<m && nCol>=0) && (vis[nRow][nCol] == 0 && grid[nRow][nCol] == 1)){
                    q.add(new int[]{nRow,nCol,t+1});
                    vis[nRow][nCol] = 1;
                    oranges++;
                }
            }
        }
        return oranges==freshOranges?time:-1;
    }
}