#include <bits/stdc++.h>
using namespace std;

// Runtime - 20ms || Memory - 27.38 MB
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// Runtime - 23ms || Memory - 31.56 MB
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        list<int> temp;
        for (int i = nums.size() - 1; i >= nums.size() - k; i--)
        {
            temp.push_front(nums[i]);
        }
        for (int i = nums.size() - k - 1; i >= 0; i--)
        {
            nums[i + k] = nums[i];
        }
        int ind = 0;
        for (auto it : temp)
        {
            nums[ind++] = it;
        }
    }
};

int main()
{
    return 0;
}