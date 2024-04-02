#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms | Memory - 7.65 MB
class Solution
{
public:
    string generateTheString(int n)
    {
        if (n % 2 != 0)
        {
            return string(n, 'a');
        };
        return string(n - 1, 'a') + 'b';
    }
};
int main()
{
    return 0;
}