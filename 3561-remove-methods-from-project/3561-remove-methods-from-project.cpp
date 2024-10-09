class Solution {
public:
    void dfs(vector<int> adj[], int node, vector<int> &vis){
        vis[node] = 1;
        for (int child: adj[node]){
            if (!vis[child]) dfs(adj,child,vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> adj[n];
        for (auto &x: invocations){
            adj[x[0]].emplace_back(x[1]);
        }
        vector<int> vis(n,0);
        dfs(adj,k,vis);
        bool c = false;
        for (int i = 0; i < n; i++){
            bool tmp = false;
            if (!vis[i]){
                for (int x: adj[i]){
                    if (vis[x]){
                        tmp = true;
                        break;
                    }
                }
                if (tmp){
                    c = true;
                    break;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++){
            if (vis[i]){
                if (c) ans.emplace_back(i);
            } else {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};