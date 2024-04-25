#include <bits/stdc++.h>
using namespace std;

// Runtime - 3ms || Memory - 16.38 MB
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int maxProduct = INT_MIN;
        int prefixMult = 1, suffixMult = 1;
        for (int i = 0; i < n; i++)
        {
            if (prefixMult == 0)
                prefixMult = 1;
            if (suffixMult == 0)
                suffixMult = 1;
            prefixMult *= nums[i];
            suffixMult *= nums[n - i - 1];
            maxProduct = max(maxProduct, max(prefixMult, suffixMult));
        }
        return maxProduct;
    }
};

int main()
{
    return 0;
}