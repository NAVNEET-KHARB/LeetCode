class Solution {
    private List<String> constructList(char[][] board){
        List<String> solution = new ArrayList<>();
        for(char[] row : board){
            solution.add(new String(row));
        }
        return solution;
    }
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
    private void solve(int col, int n, char[][] board, List<List<String>> ans){
        if(col == n){
            ans.add(constructList(board));
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
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        char[][] board = new char[n][n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                board[i][j] = '.';
            }
        }
        solve(0,n,board,ans);
        return ans;
    }
}