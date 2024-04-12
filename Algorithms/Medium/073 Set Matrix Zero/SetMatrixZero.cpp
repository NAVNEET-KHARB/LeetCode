#include <bits/stdc++.h>
using namespace std;

// Runtime - 3ms || Memory - 16.25 MB
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int col0 = 1;
        // Marking rows and columns to be changed
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // Mark the row
                    matrix[i][0] = 0;
                    // Marking the columns
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }
        // Changing the elements but not touching the marked places
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < columns; j++)
            {
                if (matrix[i][j] != 0)
                {
                    // Checking if either row or column are marked
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        // Changing the columns first so that the value at matrix[0][0] isn't changed.
        if (matrix[0][0] == 0)
        {
            for (int j = 1; j < columns; j++)
            {
                if (matrix[0][j] != 0)
                    matrix[0][j] = 0;
            }
        }
        // Changing the rows remaining elements
        if (col0 == 0)
        {
            for (int i = 0; i < rows; i++)
            {
                if (matrix[i][0] != 0)
                    matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    return 0;
}