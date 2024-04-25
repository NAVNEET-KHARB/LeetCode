#include <bits/stdc++.h>
using namespace std;

// Runtime - 10ms | Memory - 7.06 MB
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        int last = fib(n - 1);
        int slast = fib(n - 2);
        return last + slast;
    }
};

// Runtime - 3ms | Memory - 7.23 MB
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 0)
            return 0;
        else if (n == 1)
            return 1;
        int p0 = 0;
        int p1 = 1;
        for (int i = 2; i <= n; i++)
        {
            int new_p = p0 + p1;
            p0 = p1;
            p1 = new_p;
        }
        return p1;
    }
};

int main()
{
    return 0;
}