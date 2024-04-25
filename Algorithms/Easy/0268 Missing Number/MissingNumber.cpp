#include <bits/stdc++.h>
using namespace std;

// Runtime - 11ms || Memory - 20.29 MB
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // Using Sum
        int sum = (nums.size() * (nums.size() + 1)) / 2;
        for (int i = 0; i < nums.size(); i++)
        {
            sum -= nums[i];
        }
        return sum;
    }
};

// Runtime - 11ms || Memory - 20.24 MB
class Solutions
{
public:
    int missingNumber(vector<int> &nums)
    {
        // Using XOR
        int xor1 = 0, xor2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xor1 = xor1 ^ (i + 1);
            xor2 = xor2 ^ nums[i];
        }
        return (xor1 ^ xor2);
    }
};

int main()
{
    return 0;
}