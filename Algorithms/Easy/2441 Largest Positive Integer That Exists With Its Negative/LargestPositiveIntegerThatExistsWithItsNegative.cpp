#include <bits/stdc++.h>
using namespace std;

// Runtime - 13ms || Memory - 22.83 MB
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        sort(nums.begin(), nums.end());
        int ans = -1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == 0)
            {
                return nums[right];
            }
            else if (sum > 0)
            {
                right--;
            }
            else
                left++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}