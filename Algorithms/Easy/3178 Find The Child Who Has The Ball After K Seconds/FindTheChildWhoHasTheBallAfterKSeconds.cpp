#include <bits/stdc++.h>
using namespace std;

// Runtime - 2ms || Memory - 7.57 MB
class Solution
{
public:
    int numberOfChild(int n, int k)
    {
        int i = 0;
        int dir = 1;
        while (k)
        {
            if (i == 0)
                dir = 1;
            if (i == n - 1)
                dir = 0;
            if (dir == 1)
                i++;
            if (dir == 0)
                i--;
            k--;
        }
        return i;
    }
};

int main()
{
    return 0;
}