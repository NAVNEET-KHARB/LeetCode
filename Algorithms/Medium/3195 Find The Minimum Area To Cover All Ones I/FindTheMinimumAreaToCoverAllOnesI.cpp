#include <bits/stdc++.h>
using namespace std;

// Runtime - 267ms || Memory - 132.10 MB
class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int minRow = INT_MAX, maxRow = INT_MIN;
        int minCol = INT_MAX, maxCol = INT_MIN;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == 1)
                {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        if (minRow == INT_MAX)
        {
            return 0;
        }
        int area = (maxRow - minRow + 1) * (maxCol - minCol + 1);
        return area;
    }
};

int main()
{
    return 0;
}