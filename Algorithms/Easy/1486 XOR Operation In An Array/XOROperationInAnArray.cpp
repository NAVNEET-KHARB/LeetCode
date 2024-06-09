#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 7.14 MB
class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int ans = 0;
        int cnt = 0;
        int x = start;
        while (cnt < n)
        {
            ans ^= x;
            x += 2;
            cnt++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}