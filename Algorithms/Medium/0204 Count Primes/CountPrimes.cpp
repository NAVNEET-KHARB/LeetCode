#include <bits/stdc++.h>
using namespace std;

// Runtime - 141ms || Memory - 131.71 MB
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> prime(n + 1);
        for (int i = 2; i < n; i++)
        {
            prime[i] = 1;
        }
        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
                count++;
        }
        return count;
    }
};

int main()
{
    return 0;
}