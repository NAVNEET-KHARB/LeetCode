class Solution {
    public ArrayList<Integer> bfs(int start, int[] vis, ArrayList<ArrayList<Integer>> adj){
        ArrayList<Integer> nodes = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        while(!q.isEmpty()){
            int curr = q.poll();
            if(vis[curr] == 1) continue;
            nodes.add(curr);
            vis[curr] = 1;
            for(int node : adj.get(curr)) q.add(node);
        }
        return nodes;
    }
    public int countCompleteComponents(int n, int[][] edges) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i = 0; i<n; i++) adj.add(new ArrayList<Integer>());
        for(int i = 0; i<edges.length; i++){
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
        }
        int[] vis = new int[n];
        int completeComponents = 0;
        for(int i = 0; i<n; i++){
            if(vis[i] == 0){
                ArrayList<Integer> component = bfs(i,vis,adj);
                boolean isComplete = true;
                for(int node : component){
                    if(adj.get(node).size() != component.size()-1){
                        isComplete = false;
                        break;
                    }
                }
                if(isComplete) completeComponents++;
            }
        }
        return completeComponents;
    }
}