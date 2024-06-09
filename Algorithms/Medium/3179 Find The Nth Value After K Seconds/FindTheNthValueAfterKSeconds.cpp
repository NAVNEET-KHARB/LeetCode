#include <bits/stdc++.h>
using namespace std;

// Runtime - 222ms || Memory - 8.48 MB
class Solution
{
public:
    int valueAfterKSeconds(int n, int k)
    {
        const int MOD = 1000000007;
        vector<int> arr(n, 1);
        while (k)
        {
            int sum = 1;
            for (int i = 1; i < n; i++)
            {
                arr[i] = (arr[i] + sum) % MOD;
                sum = arr[i] % MOD;
            }
            k--;
        }
        return arr[n - 1];
    }
};

int main()
{
    return 0;
}