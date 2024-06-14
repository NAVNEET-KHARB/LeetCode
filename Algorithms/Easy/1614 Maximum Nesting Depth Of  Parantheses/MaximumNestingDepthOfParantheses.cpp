#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 7.40 MB
class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0;
        int mover = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                mover++;
            }
            else if (c == ')')
            {
                mover--;
            }
            depth = max(depth, mover);
        }
        return depth;
    }
};

int main()
{
    return 0;
}