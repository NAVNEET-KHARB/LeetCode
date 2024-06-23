#include <bits/stdc++.h>
using namespace std;

// Runtime - 61ms || Memory - 54.54 MB
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        deque<int> increase;
        deque<int> decrease;
        int max_len = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            while (!increase.empty() && nums[right] < increase.back())
            {
                increase.pop_back();
            }
            increase.push_back(nums[right]);
            while (!decrease.empty() && nums[right] > decrease.back())
            {
                decrease.pop_back();
            }
            decrease.push_back(nums[right]);
            while (decrease.front() - increase.front() > limit)
            {
                if (nums[left] == decrease.front())
                {
                    decrease.pop_front();
                }
                if (nums[left] == increase.front())
                {
                    increase.pop_front();
                }
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

int main()
{
    return 0;
}