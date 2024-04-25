#include <bits/stdc++.h>
using namespace std;

// Runtime - 30ms || Memory - 24.60 MB
class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int high = *max_element(nums.begin(), nums.end());
        if (nums.size() == threshold)
        {
            return high;
        }
        int low = 1;
        int ans;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int num : nums)
            {
                if (num % mid != 0)
                    count++;
                count += num / mid;
            }
            if (count > threshold)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};

// Runtime - 33ms || Memory - 24.61 MB
class Solution
{
public:
    int divSum(vector<int> &nums, int mid)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += ceil((double)num / (double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int ans = -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        if (threshold == nums.size())
            return high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (divSum(nums, mid) <= threshold)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

int main()
{
    return 0;
}