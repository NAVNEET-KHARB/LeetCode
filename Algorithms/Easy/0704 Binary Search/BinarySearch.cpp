#include <bits/stdc++.h>
using namespace std;

// Runtime - 12ms || Memory - 29.70 MB
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

// Runtime - 26ms || Memory - 29.72 MB
class Solution
{
public:
    int bs(vector<int> &nums, int low, int high, int target)
    {
        if (low > high)
            return -1;
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            return bs(nums, mid + 1, high, target);
        return bs(nums, low, mid - 1, target);
    }
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        return bs(nums, 0, n - 1, target);
    }
};

int main()
{
    return 0;
}