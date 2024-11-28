class Solution {
private:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));
        minObstacles[0][0] = grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({minObstacles[0][0], 0, 0});
        while (!pq.empty()) {
            vector<int> current = pq.top();
            pq.pop();
            int obstacles = current[0], row = current[1], col = current[2];
            if (row == m - 1 && col == n - 1) {
                return obstacles;
            }
            for (vector<int>& dir : directions) {
                int newRow = row + dir[0], newCol = col + dir[1];
                if (isValid(grid, newRow, newCol)) {
                    int newObstacles = obstacles + grid[newRow][newCol];
                    if (newObstacles < minObstacles[newRow][newCol]) {
                        minObstacles[newRow][newCol] = newObstacles;
                        pq.push({newObstacles, newRow, newCol});
                    }
                }
            }
        }

        return minObstacles[m - 1][n - 1];
    }
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < grid.size() &&
               col < grid[0].size();
    }
};