#include <bits/stdc++.h>
using namespace std;

// Runtime - 15ms || Memory - 34.22 MB
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        int ts = 0;
        int madds = 0;
        int adds = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!grumpy[i])
            {
                ts += customers[i];
            }
            else
            {
                adds += customers[i];
            }
            if (i >= minutes && grumpy[i - minutes])
            {
                adds -= customers[i - minutes];
            }
            madds = max(madds, adds);
        }
        return ts + madds;
    }
};

int main()
{
    return 0;
}