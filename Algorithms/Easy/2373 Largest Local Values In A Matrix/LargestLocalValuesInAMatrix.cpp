#include <bits/stdc++.h>
using namespace std;

// Runtime - 3ms || Memory - 13.49 MB
class Solution
{
public:
    int findMax(vector<vector<int>> &grid, int x, int y)
    {
        int maxEle = 0;
        for (int i = x; i < x + 3; i++)
        {
            for (int j = y; j < y + 3; j++)
            {
                maxEle = max(maxEle, grid[i][j]);
            }
        }
        return maxEle;
    }
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                grid[i][j] = findMax(grid, i, j);
            }
        }
        grid.resize(n - 2);
        for (int i = 0; i < grid.size(); i++)
        {
            grid[i].resize(n - 2);
        }
        return grid;
    }
};

// Runtime - 10ms || Memory - 13.56 MB
class Solution
{
public:
    int findMax(vector<vector<int>> &grid, int x, int y)
    {
        int maxEle = 0;
        for (int i = x; i < x + 3; i++)
        {
            for (int j = y; j < y + 3; j++)
            {
                maxEle = max(maxEle, grid[i][j]);
            }
        }
        return maxEle;
    }
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, 0));
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                maxLocal[i][j] = findMax(grid, i, j);
            }
        }
        return maxLocal;
    }
};

int main()
{
    return 0;
}