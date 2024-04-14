#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 8.08 MB
class Solution
{
public:
    vector<int> generateRow(int row)
    {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for (int column = 1; column < row; column++)
        {
            ans = ans * (row - column);
            ans = ans / column;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int row = 1; row <= numRows; row++)
        {
            ans.push_back(generateRow(row));
        }
        return ans;
    }
};

int main()
{
    return 0;
}