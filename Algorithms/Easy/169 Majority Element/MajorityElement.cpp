#include <bits/stdc++.h>
using namespace std;

// Runtime - 19ms || Memory - 26.71 MB
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Using Map
        map<int, int> counter;
        for (int i = 0; i < nums.size(); i++)
        {
            counter[nums[i]]++;
        }
        for (auto it : counter)
        {
            if (it.second > (nums.size() / 2))
                return it.first;
        }
        return -1;
    }
};

// Runtime - 12ms || Memory - 26.63 MB
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Using Moore's Algo
        int count = 0;
        int currentElement;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                count = 1;
                currentElement = nums[i];
            }
            else if (nums[i] == currentElement)
                count++;
            else
                count--;
        }
        return currentElement;
    }
};

int main()
{
    return 0;
}