class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> solution = new ArrayList<>();
        char board[][] = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = '.';
            }
        }
        helper(board, solution, 0, n);
        return solution;
    }

    public void helper(char board[][], List<List<String>> solution, int row, int n) {
        if (row == n) {
            solution.add(construstSolution(board));
            return;
        }
        for (int i = 0; i < n; i++) {
            if (ifSafe(row, i, board, n)) {
                board[row][i] = 'Q';
                helper(board, solution, row + 1, n);
                board[row][i] = '.';
            }
        }
    }

    public boolean ifSafe(int x, int y, char board[][], int n) {
        for (int i = 0; i < x; i++) {
            if (board[i][y] == 'Q') {
                return false;
            }
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    public List<String> construstSolution(char board[][]) {
        List<String> result = new ArrayList<>();
        for (char row[] : board) {
            result.add(new String(row));
        }
        return result;
    }
}