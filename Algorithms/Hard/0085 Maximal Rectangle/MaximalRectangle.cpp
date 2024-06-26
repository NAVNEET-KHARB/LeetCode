#include <bits/stdc++.h>
using namespace std;

// Runtime - 26ms || Memory - 17.35 MB
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int maxA = 0;
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, height * width);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int max1A = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            max1A = max(max1A, largestRectangleArea(heights));
        }
        return max1A;
    }
};

int main()
{
    return 0;
}