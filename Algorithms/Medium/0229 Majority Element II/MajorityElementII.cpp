#include <bits/stdc++.h>
using namespace std;

// Runtime - 14ms || Memory - 18.34 MB
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && nums[i] != el2)
            {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && nums[i] != el1)
            {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (el1 == nums[i])
                cnt1++;
            else if (el2 == nums[i])
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (el1 == nums[i])
                cnt1++;
            else if (el2 == nums[i])
                cnt2++;
        }
        int mini = n / 3;
        if (cnt1 > mini)
            ans.push_back(el1);
        if (cnt2 > mini)
            ans.push_back(el2);
        return ans;
    }
};
int main()
{
    return 0;
}