class Solution {
    public boolean isValid(int row, int col, int rows, int cols){
        return ((row>=0 && row<rows) && (col>=0 && col<cols));
    }
    public int[] maxPoints(int[][] grid, int[] queries) {
        int rows = grid.length, cols = grid[0].length;
        int k = queries.length;
        int[] ans = new int[k];
        int[][] queryIndices = new int[k][2];
        for(int i = 0; i<k; i++) queryIndices[i] = new int[]{queries[i],i};
        Arrays.sort(queryIndices,Comparator.comparingInt(a->a[0]));
        int[] dRow = {-1,0,1,0};
        int[] dCol = {0,1,0,-1};
        int[][] vis = new int[rows][cols];
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
        pq.add(new int[]{grid[0][0],0,0});
        vis[0][0] = 1;
        int cnt = 0, index = 0;
        while(index<k){
            int threshold = queryIndices[index][0];
            while(!pq.isEmpty() && pq.peek()[0]<threshold){
                int[] coord = pq.poll();
                int row = coord[1], col = coord[2];
                cnt++;
                for(int dir = 0; dir<4; dir++){
                    int nRow = row + dRow[dir];
                    int nCol = col + dCol[dir];
                    if(isValid(nRow,nCol,rows,cols) && vis[nRow][nCol] == 0){
                        vis[nRow][nCol] = 1;
                        pq.add(new int[]{grid[nRow][nCol],nRow,nCol});
                    }
                }
            }
            ans[queryIndices[index++][1]] = cnt;
        }
        return ans;
    }
}