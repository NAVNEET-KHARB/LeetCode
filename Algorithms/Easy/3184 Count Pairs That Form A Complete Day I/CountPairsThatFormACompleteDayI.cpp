#include <bits/stdc++.h>
using namespace std;

// Runtime - 4ms || Memory - 22.72 MB
class Solution
{
public:
    int countCompleteDayPairs(vector<int> &hours)
    {
        int n = hours.size();
        int pairs = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((hours[i] + hours[j]) % 24 == 0)
                    pairs++;
            }
        }
        return pairs;
    }
};

int main()
{
    return 0;
}