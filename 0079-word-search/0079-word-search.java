class Solution {
    public boolean dfs(char[][] board, String word, int idx, int row, int col) {
        if (idx == word.length()) return true;
        if (row < 0 || row >= board.length || col < 0 || col >= board[0].length) return false;
        if (board[row][col] != word.charAt(idx)) return false;
        char temp = board[row][col];
        board[row][col] = '#';
        boolean found =
            dfs(board, word, idx + 1, row + 1, col) ||
            dfs(board, word, idx + 1, row - 1, col) ||
            dfs(board, word, idx + 1, row, col + 1) ||
            dfs(board, word, idx + 1, row, col - 1);
        board[row][col] = temp;
        return found;
    }
    public boolean exist(char[][] board, String word) {
        int m = board.length, n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
}