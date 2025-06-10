class Solution {
    private void dfs(int[][] image, int row, int col, int color, int ogCol, int n, int m, int[] dRow, int[] dCol){
        for(int i = 0; i<4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if((nRow<n && nRow>=0) && (nCol<m && nCol>=0) && image[nRow][nCol] == ogCol){
                image[nRow][nCol] = color;
                dfs(image,nRow,nCol,color,ogCol,n,m,dRow,dCol);
            }
        }
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int n = image.length;
        int m = image[0].length;
        int ogCol = image[sr][sc];
        if (ogCol == color) return image;
        int[] dRow = {-1,0,1,0};
        int[] dCol = {0,1,0,-1};
        image[sr][sc] = color;
        dfs(image,sr,sc,color,ogCol,n,m,dRow,dCol);
        return image;
    }
}