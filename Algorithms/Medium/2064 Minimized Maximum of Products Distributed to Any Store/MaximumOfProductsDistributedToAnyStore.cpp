#include <bits/stdc++.h>
using namespace std;

// Runtime - 135ms || Memory - 86.81 MB
class Solution
{
public:
    bool isDistributionPossible(int stores, vector<int> &quantities, int items, int n)
    {
        int currStore = 0;
        for (int i = 0; i < n; i++)
        {
            currStore += quantities[i] / items;
            if (quantities[i] % items != 0)
            {
                currStore++;
            }
            if (currStore > stores)
                return false;
        }
        return true;
    }
    int minimizedMaximum(int stores, vector<int> &quantities)
    {
        int n = quantities.size();
        if (n == 1)
            return quantities[0];
        int low = 1, high = INT_MIN;
        for (int i = 0; i < quantities.size(); i++)
        {
            high = max(quantities[i], high);
        }
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isDistributionPossible(stores, quantities, mid, n) == true)
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    return 0;
}