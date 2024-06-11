#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 10.06 MB
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> expected(heights.begin(), heights.end());
        sort(expected.begin(), expected.end());
        int n = expected.size();
        int changes = 0;
        for (int i = 0; i < n; i++)
        {
            if (heights[i] != expected[i])
                changes++;
        }
        return changes;
    }
};

int main()
{
    return 0;
}