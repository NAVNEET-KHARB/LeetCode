#include <bits/stdc++.h>
using namespace std;

// Runtime - 119ms || Memory - 94.11 MB
class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int ans = 0;
        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                temp++;
            }
        }
        ans = max(temp, ans);
        temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 1)
            {
                temp++;
            }
        }
        ans = max(temp, ans);
        temp = 0;
        int cmp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == cmp)
            {
                temp++;
                cmp = (cmp + 1) % 2;
            }
        }
        ans = max(temp, ans);
        temp = 0;
        cmp = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == cmp)
            {
                temp++;
                cmp = (cmp + 1) % 2;
            }
        }
        ans = max(temp, ans);
        return ans;
    }
};

int main()
{
    return 0;
}