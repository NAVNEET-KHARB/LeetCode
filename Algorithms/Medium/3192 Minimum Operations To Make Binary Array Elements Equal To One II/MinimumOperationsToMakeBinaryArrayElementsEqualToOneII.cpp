#include <bits/stdc++.h>
using namespace std;

// Runtime - 136ms || Memory - 154.75 MB
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int operations = 0;
        bool flip = false;
        for (int i = 0; i < n; i++)
        {
            if ((nums[i] == 0 && !flip) || (nums[i] == 1 && flip))
            {
                operations++;
                flip = !flip;
            }
        }
        return operations;
    }
};

int main()
{
    return 0;
}