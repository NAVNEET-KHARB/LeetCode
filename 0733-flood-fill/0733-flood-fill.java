class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int n = image.length;
        int m = image[0].length;
        int ogCol = image[sr][sc];
        if (ogCol == color) return image;
        int[] dRow = {-1,0,1,0};
        int[] dCol = {0,1,0,-1};
        image[sr][sc] = color;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{sr,sc});
        while(!q.isEmpty()){
            int[] cell = q.poll();
            int row = cell[0], col = cell[1];
            for(int i = 0; i<4; i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                if((nRow<n && nRow>=0) && (nCol<m && nCol>=0) && image[nRow][nCol] == ogCol){
                    image[nRow][nCol] = color;
                    q.add(new int[]{nRow,nCol});
                }
            }
        }
        return image;
    }
}