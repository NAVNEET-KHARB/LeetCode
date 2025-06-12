class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int[][] vis = new int[n][m];
        int[][] dis = new int[n][m];
        int[] dRow = {-1,0,1,0};
        int[] dCol = {0,1,0,-1};
        Queue<int[]> q = new LinkedList<>();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.add(new int[]{i,j,0});
                }
            }
        }
        while(!q.isEmpty()){
            int qSize = q.size();
            for(int i = 0; i<qSize; i++){
                int[] cell = q.poll();
                int row = cell[0], col = cell[1], steps = cell[2];
                dis[row][col] = steps;
                for(int dir = 0; dir<4; dir++){
                    int nRow = row + dRow[dir];
                    int nCol = col + dCol[dir];
                    if((nRow<n && nRow>=0) && (nCol<m && nCol>=0) && vis[nRow][nCol] == 0){
                        vis[nRow][nCol] = 1;
                        q.add(new int[]{nRow,nCol,steps+1});
                    }
                }
            }
        }
        return dis;
    }
}