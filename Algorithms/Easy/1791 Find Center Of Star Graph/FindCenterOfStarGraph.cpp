#include <bits/stdc++.h>
using namespace std;

// Runtime - 120ms || Memory - 70.69 MB
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};

int main()
{
    return 0;
}