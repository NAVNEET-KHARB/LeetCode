#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 8.58 MB
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 1)
            return;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (auto &row : matrix)
        {
            reverse(row.begin(), row.end());
        }
    }
};

// Runtime - 0ms || Memory - 8.58 MB
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 1)
            return;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (auto &row : matrix)
        {
            reverse(row.begin(), row.end());
        }
    }
};

int main()
{
    return 0;
}