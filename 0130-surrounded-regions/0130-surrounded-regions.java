class Solution {
    private void dfs(int row, int col, int n, int m, int[] dRow, int[] dCol, int[][] vis, char[][] board){
        vis[row][col] = 1;
        for(int i = 0; i<4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if((nRow<n && nRow>=0) && (nCol<m && nCol>=0) && (vis[nRow][nCol] == 0 && board[nRow][nCol] == 'O')) dfs(nRow,nCol,n,m,dRow,dCol,vis,board);
        }
    }
    public void solve(char[][] board) {
        int n = board.length;
        int m = board[0].length;
        int[] dRow = {-1,0,1,0};
        int[] dCol = {0,1,0,-1};
        int[][] vis = new int[n][m];
        for(int i = 0; i<n; i++){
            if(vis[i][0] == 0 && board[i][0] == 'O') dfs(i,0,n,m,dRow,dCol,vis,board);
            if(vis[i][m-1] == 0 && board[i][m-1] == 'O') dfs(i,m-1,n,m,dRow,dCol,vis,board);
        }
        for(int i = 0; i<m; i++){
            if(vis[0][i] == 0 && board[0][i] == 'O') dfs(0,i,n,m,dRow,dCol,vis,board);
            if(vis[n-1][i] == 0 && board[n-1][i] == 'O') dfs(n-1,i,n,m,dRow,dCol,vis,board);
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == 'O' && vis[i][j] == 0) board[i][j] = 'X';
            }
        }
    }
}