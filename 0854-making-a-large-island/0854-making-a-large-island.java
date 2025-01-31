class Solution {
    class DisjointSet {
        int[] size;
        int[] parent;
        DisjointSet(int n) {
            size = new int[n+1];
            parent = new int[n+1];
            for (int i = 0; i <= n; i++){
                size[i] = 1;
                parent[i] = i;
            }
        }
        int findUpar(int node) {
            if (node == parent[node]) return node;
            return parent[node] = findUpar(parent[node]);
        }
        void unionBySize(int u, int v) {
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    }
    boolean isValid(int row, int col, int n) {
        return ((row >= 0 && row < n) && (col >= 0 && col < n));
    }
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        DisjointSet ds = new DisjointSet(n * n);
        boolean allLand = true;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) allLand = false;
            }
        }
        if (allLand) return n * n;
        int[] dRow = {1, 0, -1, 0};
        int[] dCol = {0, 1, 0, -1};
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                for (int ind = 0; ind < 4; ind++) {
                    int nRow = row + dRow[ind];
                    int nCol = col + dCol[ind];
                    if (isValid(nRow, nCol, n) && grid[nRow][nCol] == 1) {
                        int nodeNo = row * n + col;
                        int nNodeNo = nRow * n + nCol;
                        ds.unionBySize(nodeNo, nNodeNo);
                    }
                }
            }
        }
        int ans = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                HashSet<Integer> comp = new HashSet<>();
                for (int ind = 0; ind < 4; ind++) {
                    int nRow = row + dRow[ind];
                    int nCol = col + dCol[ind];
                    if (isValid(nRow, nCol, n)) {
                        if (grid[nRow][nCol] == 1) {
                            comp.add(ds.findUpar(nRow * n + nCol));
                        }
                    }
                }
                int totalSize = 1;
                for (int it : comp) {
                    totalSize += ds.size[it];
                }
                ans = Math.max(ans, totalSize);
            }
        }
        return ans;
    }
}