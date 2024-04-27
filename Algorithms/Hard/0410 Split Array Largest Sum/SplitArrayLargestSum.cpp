#include <bits/stdc++.h>
using namespace std;

// Runtime - 4ms || Memory - 8.98 MB
class Solution
{
public:
    int subArray(vector<int> &nums, int sum)
    {
        long long currSum = 0;
        int currSubArray = 1;
        for (int num : nums)
        {
            if (currSum + num <= sum)
            {
                currSum += num;
            }
            else
            {
                currSubArray++;
                currSum = num;
            }
        }
        return currSubArray;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        if (n == k)
            return low;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (subArray(nums, mid) > k)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return low;
    }
};

int main()
{
    return 0;
}