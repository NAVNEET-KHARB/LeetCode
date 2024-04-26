#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 11.96 MB
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return (low + k);
    }
};

int main()
{
    return 0;
}