#include <bits/stdc++.h>
using namespace std;

// Runtime - 63ms || Memory - 32.10 MB
class Solution
{
public:
    vector<int> countPrimes(int n)
    {
        vector<int> ans;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                ans.push_back(i);
                while (n % i == 0)
                {
                    n /= i;
                }
            }
        }
        if (n != 1)
            ans.push_back(n);
        return ans;
    }
    int distinctPrimeFactors(vector<int> &nums)
    {
        unordered_set<int> primes;
        for (auto &num : nums)
        {
            vector<int> primeFac = countPrimes(num);
            primes.insert(primeFac.begin(), primeFac.end());
        }
        return primes.size();
    }
};

int main()
{
    return 0;
}