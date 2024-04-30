#include <bits/stdc++.h>
using namespace std;

// Runtime - 127ms || Memory - 48.95 MB
class Solution
{
public:
    int maxRowEle(vector<vector<int>> &mat, int n, int col)
    {
        int maxVal = -1;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][col] > maxVal)
            {
                maxVal = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int row = maxRowEle(mat, n, mid);
            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < m ? mat[row][mid + 1] : -1;
            if (mat[row][mid] > left && mat[row][mid] > right)
            {
                return {row, mid};
            }
            else if (mat[row][mid] < left)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};

int main()
{
    return 0;
}