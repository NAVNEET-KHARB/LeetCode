#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 11.93 MB
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0;
        int high = rows * cols - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int row = mid / cols, col = mid % cols;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};

int main()
{
    return 0;
}