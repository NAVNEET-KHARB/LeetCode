class Solution {
    private boolean doesnotCollide(int row, int col, int n, char[][] board){
        int cRow = row, cCol = col;
        while(cCol>=0){
            if(board[cRow][cCol] == 'Q') return false;
            cCol--;
        }
        cCol = col;
        while(cRow>=0 && cCol>=0){
            if(board[cRow][cCol] == 'Q') return false;
            cRow--;
            cCol--;
        }
        cRow = row;
        cCol = col;
        while(cRow<n && cCol>=0){
            if(board[cRow][cCol] == 'Q') return false;
            cRow++;
            cCol--;
        }
        return true;
    }
    private void solve(int col, int n, char[][] board, int[] ans){
        if(col == n){
            ans[0]++;
            return;
        }
        for(int row = 0; row<n; row++){
            if(doesnotCollide(row,col,n,board)){
                board[row][col] = 'Q';
                solve(col+1,n,board,ans);
                board[row][col] = '.';
            }
        }
    }
    public int totalNQueens(int n) {
        char[][] board = new char[n][n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                board[i][j] = '.';
            }
        }
        int[] ans = new int[1];
        solve(0,n,board,ans);
        return ans[0];
    }
}