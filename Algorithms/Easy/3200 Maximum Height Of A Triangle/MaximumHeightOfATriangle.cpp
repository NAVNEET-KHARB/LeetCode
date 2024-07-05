#include <bits/stdc++.h>
using namespace std;

// Runtime - 2ms || Memory - 7.48 MB
class Solution
{
    int height(int red, int blue, char curr, int level)
    {
        int ans = 0;
        while (true)
        {
            if (curr == 'B')
            {
                if (blue < level)
                {
                    break;
                }
                blue = blue - level;
                ans++;
                level++;
                curr = 'R';
            }
            else
            {
                if (red < level)
                {
                    break;
                }
                red = red - level;
                ans++;
                level++;
                curr = 'B';
            }
        }
        return ans;
    }

public:
    int maxHeightOfTriangle(int red, int blue)
    {
        return max(height(red, blue, 'R', 1), height(red, blue, 'B', 1));
    }
};

int main()
{
    return 0;
}