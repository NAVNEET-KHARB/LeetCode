#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 10.08 MB
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int sort = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] < nums[i])
                sort++;
        }
        if (sort == 0)
            return true; // array is sorted
        if (sort == 1)
        {
            if (nums[nums.size() - 1] <= nums[0])
                return true; // array was sorted but now rotated
        }
        return false;
    }
};

int main()
{
    return 0;
}