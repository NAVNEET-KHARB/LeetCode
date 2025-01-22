class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int[][] vis = new int[n][m];
        int[][] dist = new int[n][m];
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.add(new int[]{i, j, 0});
                }
            }
        }
        int[] delRow = {1, 0, -1, 0};
        int[] delCol = {0, 1, 0, -1};
        while (!q.isEmpty()) {
            int qSize = q.size();
            for(int i = 0; i<qSize; i++){
                int[] current = q.poll();
                int row = current[0];
                int col = current[1];
                int steps = current[2];
                dist[row][col] = steps;
                for (int j = 0; j < 4; j++) {
                    int nRow = row + delRow[j];
                    int nCol = col + delCol[j];
                    if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] == 0) {
                        vis[nRow][nCol] = 1;
                        q.add(new int[]{nRow, nCol, steps + 1});
                    }
                }
            }
        }
        return dist;
    }
}