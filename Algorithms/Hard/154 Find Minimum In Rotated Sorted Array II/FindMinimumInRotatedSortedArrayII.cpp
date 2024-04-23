#include <bits/stdc++.h>
using namespace std;

// Runtime - 9ms || Memory - 14.66 MB
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[low] < nums[high])
            {
                ans = min(ans, nums[low]);
                break;
            }
            else if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                ans = min(ans, nums[low]);
                low++;
                high--;
                continue;
            }
            if (nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else
            {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}