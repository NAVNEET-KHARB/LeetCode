#include <bits/stdc++.h>
using namespace std;

// Runtime - 7ms || Memory - 22.29 MB
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int waterTrapped = 0;
        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    waterTrapped += leftMax - height[left];
                left++;
            }
            else
            {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    waterTrapped += rightMax - height[right];
                right--;
            }
        }
        return waterTrapped;
    }
};

int main()
{
    return 0;
}