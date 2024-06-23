#include <bits/stdc++.h>
using namespace std;

// Runtime - 8ms || Memory - 22.17 MB
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int moves = 0;
        for (int num : nums)
        {
            if (num % 3)
                moves++;
        }
        return moves;
    }
};

int main()
{
    return 0;
}