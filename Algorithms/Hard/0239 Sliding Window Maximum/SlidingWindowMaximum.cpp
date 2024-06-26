#include <bits/stdc++.h>
using namespace std;

// Runtime - 161ms || Memory - 137.12 MB
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> output;
        deque<int> dq;
        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() && dq.front() == i - k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
                output.push_back(nums[dq.front()]);
        }
        return output;
    }
};

int main()
{
    return 0;
}