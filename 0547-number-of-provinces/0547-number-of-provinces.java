class Solution {
    private void dfs(int node, int[] vis, int[][] isConnected){
        if(vis[node] == 1) return;
        vis[node] = 1;
        for(int i = 0; i<isConnected[node].length; i++){
            if(isConnected[node][i] == 1) dfs(i,vis,isConnected);
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        int[] vis = new int[n];
        int provinces = 0;
        for(int i = 0; i<n; i++){
            if(vis[i] == 0){
                dfs(i,vis,isConnected);
                provinces++;
            }
        }
        return provinces;
    }
}