#include <bits/stdc++.h>
using namespace std;

// Runtime - 4ms || Memory - 16.62 MB
class Solution
{
public:
    int firstInd(vector<int> arr, int n, int x)
    {
        int low = 0, high = n - 1, first = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
            {
                first = mid;
                high = mid - 1;
            }
            else if (arr[mid] > x)
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return first;
    }
    int lastInd(vector<int> arr, int n, int x)
    {
        int low = 0, high = n - 1, last = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
            {
                last = mid;
                low = mid + 1;
            }
            else if (arr[mid] > x)
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return last;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        return {firstInd(nums, n, target), lastInd(nums, n, target)};
    }
};

// Runtime - 6ms || Memory - 15.94 MB
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int lowF = 0, highF = n - 1;
        int lowL = 0, highL = n - 1;
        int first = -1, last = -1;
        while (lowF <= highF || lowL <= highL)
        {
            int midF = lowF + (highF - lowF) / 2;
            if (nums[midF] == target)
            {
                first = midF;
                highF = midF - 1;
            }
            else if (nums[midF] > target)
            {
                highF = midF - 1;
            }
            else
                lowF = midF + 1;
            int midL = lowL + (highL - lowL) / 2;
            if (nums[midL] == target)
            {
                last = midL;
                lowL = midL + 1;
            }
            else if (nums[midL] > target)
            {
                highL = midL - 1;
            }
            else
                lowL = midL + 1;
        }
        return {first, last};
    }
};

int main()
{
    return 0;
}