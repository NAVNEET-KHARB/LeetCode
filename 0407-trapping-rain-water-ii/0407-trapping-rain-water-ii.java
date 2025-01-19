class Solution {
    public int trapRainWater(int[][] heightMap) {
        int rows = heightMap.length;
        int cols = heightMap[0].length;
        boolean[][] visited = new boolean[rows][cols];
        int[] dCol = { 0, 1, 0, -1 };
        int[] dRow = { 1, 0, -1, 0 };
        PriorityQueue<Cell> q = new PriorityQueue<>();
        for (int i = 0; i < rows; i++) {
            q.offer(new Cell(heightMap[i][0], i, 0));
            q.offer(new Cell(heightMap[i][cols - 1], i, cols - 1));
            visited[i][0] = visited[i][cols - 1] = true;
        }
        for (int i = 0; i < cols; i++) {
            q.offer(new Cell(heightMap[0][i], 0, i));
            q.offer( new Cell(heightMap[rows - 1][i], rows - 1, i));
            visited[0][i] = visited[rows - 1][i] = true;
        }
        int totalWaterVolume = 0;
        while (!q.isEmpty()) {
            Cell currCell = q.poll();
            int currRow = currCell.row;
            int currCol = currCell.col;
            int minHeight = currCell.height;
            for (int dir = 0; dir < 4; dir++) {
                int nRow = currRow + dRow[dir];
                int nCol = currCol + dCol[dir];
                if (isValidCell(nRow,nCol,rows,cols) && !visited[nRow][nCol]) {
                    int nHeight = heightMap[nRow][nCol];
                    if (nHeight < minHeight)totalWaterVolume += minHeight - nHeight;
                    q.offer(new Cell(Math.max(nHeight, minHeight),nRow, nCol));
                    visited[nRow][nCol] = true;
                }
            }
        }
        return totalWaterVolume;
    }
    private static class Cell implements Comparable<Cell> {
        int height;
        int row;
        int col;
        public Cell(int height, int row, int col) {
            this.height = height;
            this.row = row;
            this.col = col;
        }
        @Override
        public int compareTo(Cell other) {
            return Integer.compare(this.height, other.height);
        }
    }
    private boolean isValidCell(int row, int col,int rows, int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
}