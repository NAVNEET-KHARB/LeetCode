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

// Runtime - 4ms || Memory - 16.60 MB
class Solution
{
public:
    int lowerBound(vector<int> arr, int n, int x)
    {
        int low = 0, high = n - 1, ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
    int upperBound(vector<int> arr, int n, int x)
    {
        int low = 0, high = n - 1, ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int lb = lowerBound(nums, n, target);
        if (lb == n || nums[lb] != target)
            return {-1, -1};
        return {lb, upperBound(nums, n, target) - 1};
    }
};

int main()
{
    return 0;
}