class Solution {
    public int minTimeToReach(int[][] moveTime) {
        int n = moveTime.length;
        int m = moveTime[0].length;
        int[][] dist = new int[n][m];
        boolean[][] vis = new boolean[n][m];
        for(int i = 0; i<n; i++) Arrays.fill(dist[i],Integer.MAX_VALUE);
        int[][] dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        dist[0][0] = 0;
        pq.add(new int[]{0,0,0});
        while(!pq.isEmpty()){
            int[] curr = pq.poll();
            if(vis[curr[1]][curr[2]]) continue;
            vis[curr[1]][curr[2]] = true;
            for(int[] dir : dirs){
                int nRow = curr[1] + dir[0];
                int nCol = curr[2] + dir[1];
                if(nRow<0 || nRow>=n || nCol<0 || nCol>=m) continue;
                int dis = Math.max(curr[0],moveTime[nRow][nCol])+1;
                if(dist[nRow][nCol]>dis){
                    dist[nRow][nCol] = dis;
                    pq.add(new int[]{dis,nRow,nCol});
                }
            }
        }
        return dist[n-1][m-1];
    }
}