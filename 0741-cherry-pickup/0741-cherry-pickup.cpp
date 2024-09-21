class Solution {
    int solve(int i1, int i2, int j1, int j2, int n,vector<vector<int>>& grid,vector<vector<vector<vector<int>>>>& dp){
        if(i1 >= n || j1 >= n || i2 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) return -1e9;
        if(dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];
        if(i1 == n-1 && j1 == n-1) return grid[i1][j1];
        int maxi = 0;
        if(i1 == i2 && j1 == j2) maxi = grid[i1][j1];
        else maxi = grid[i1][j1]+grid[i2][j2];
        maxi += max(max(solve(i1+1,i2+1,j1,j2,n,grid,dp),solve(i1+1,i2,j1,j2+1,n,grid,dp)),
        max(solve(i1,i2+1,j1+1,j2,n,grid,dp),solve(i1,i2,j1+1,j2+1,n,grid,dp)));
        return dp[i1][j1][i2][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        int ans = solve(0,0,0,0,n,grid,dp);
        if(ans<=0) return 0;
        return ans;
    }
};