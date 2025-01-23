class Solution {

    public int countServers(int[][] grid) {
        int communicableServersCount = 0;
        int[] rowCounts = new int[grid[0].length];
        int[] lastServerInCol = new int[grid.length];
        for (int i = 0; i < lastServerInCol.length; i++) {
            lastServerInCol[i] = -1;
        }
        for (int row = 0; row < grid.length; row++) {
            int serverCountInRow = 0;
            for (int col = 0; col < grid[0].length; col++) {
                if (grid[row][col] == 1) {
                    serverCountInRow++;
                    rowCounts[col]++;
                    lastServerInCol[row] = col;
                }
            }
            if (serverCountInRow != 1) {
                communicableServersCount += serverCountInRow;
                lastServerInCol[row] = -1;
            }
        }
        for (int row = 0; row < grid.length; row++) {
            if (lastServerInCol[row] != -1 && rowCounts[lastServerInCol[row]] > 1) {
                communicableServersCount++;
            }
        }

        return communicableServersCount;
    }
}