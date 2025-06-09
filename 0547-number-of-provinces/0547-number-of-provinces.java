class Solution {
    private void dfs(int node, int[] vis, ArrayList<ArrayList<Integer>> adj){
        if(vis[node] == 1) return;
        vis[node] = 1;
        for(int neighbour : adj.get(node)) dfs(neighbour,vis,adj);
    }
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i = 0; i<n; i++) adj.add(new ArrayList<>());
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj.get(i).add(j);
                    adj.get(j).add(i);
                }
            }
        }
        int[] vis = new int[n];
        int provinces = 0;
        for(int i = 0; i<n; i++){
            if(vis[i] == 0){
                dfs(i,vis,adj);
                provinces++;
            }
        }
        return provinces;
    }
}