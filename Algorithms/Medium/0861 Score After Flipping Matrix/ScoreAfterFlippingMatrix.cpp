#include <bits/stdc++.h>
using namespace std;

// Runtime - 5ms || Memory - 10.16 MB
class Solution
{
public:
    void complRows(vector<vector<int>> &grid, int rowNum, int columns)
    {
        for (int i = 0; i < columns; i++)
        {
            grid[rowNum][i] = 1 - grid[rowNum][i];
        }
    }
    void complCols(vector<vector<int>> &grid, int colNum, int rows)
    {
        for (int i = 0; i < rows; i++)
        {
            grid[i][colNum] = 1 - grid[i][colNum];
        }
    }
    int matrixScore(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int columns = grid[0].size();
        for (int i = 0; i < rows; i++)
        {
            if (grid[i][0] == 0)
            {
                complRows(grid, i, columns);
            }
        }
        for (int j = 1; j < columns; j++)
        {
            int count = 0;
            for (int i = 0; i < rows; i++)
            {
                count += grid[i][j];
            }
            if (count < rows - count)
            {
                complCols(grid, j, rows);
            }
        }

        int total = 0;
        for (int i = 0; i < rows; i++)
        {
            int factor = 1;
            for (int j = columns - 1; j >= 0; j--)
            {
                total += grid[i][j] * factor;
                factor *= 2;
            }
        }
        return total;
    }
};

int main()
{
    return 0;
}