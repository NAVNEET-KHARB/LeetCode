class Solution {
    class DisjointSet{
        private int[] size;
        private int[] parent;
        DisjointSet(int n){
            size = new int[n+1];
            parent = new int[n+1];
            Arrays.fill(size,1);
            for(int i = 0; i<=n;i++) parent[i] = i;
        }
        public int findUpar(int node){
            if(parent[node] == node) return node;
            return parent[node] = findUpar(parent[node]);
        }
        public boolean union(int u, int v){
            int ulpU = findUpar(u);
            int ulpV = findUpar(v);
            if(ulpU == ulpV) return false;
            if(size[ulpU]<size[ulpV]){
                parent[ulpU] = ulpV;
                size[ulpV] += size[ulpU];
            }else{
                parent[ulpV] = ulpU;
                size[ulpU] += size[ulpV];
            }
            return true;
        }
    }
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        DisjointSet ds = new DisjointSet(n);
        for(int i = 0; i<n; i++){
            if(!ds.union(edges[i][0],edges[i][1])) return edges[i];
        }
        return new int[]{};
    }
}