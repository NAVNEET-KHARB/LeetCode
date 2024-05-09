#include <bits/stdc++.h>
using namespace std;

// Runtime - 156ms || Memory - 107.09 MB
class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end());
        long long hSum = 0;
        int n = happiness.size();
        int dec = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (dec >= k)
                break;
            int additive = happiness[i] - dec;
            if (additive < 0)
            {
                hSum += 0;
            }
            else
                hSum += additive;
            dec++;
        }
        return hSum;
    }
};

int main()
{
    return 0;
}