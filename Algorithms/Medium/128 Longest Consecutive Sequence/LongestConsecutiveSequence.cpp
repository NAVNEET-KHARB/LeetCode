#include <bits/stdc++.h>
using namespace std;

// Runtime - 113ms || Memory - 74.06 MB
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int longest = 1;
        unordered_set<int> ust;
        for (int i = 0; i < n; i++)
        {
            ust.insert(nums[i]);
        }
        for (auto it : ust)
        {
            if (ust.find(it - 1) == ust.end())
            {
                int count = 1;
                int x = it;
                while (ust.find(x + 1) != ust.end())
                {
                    x++;
                    count++;
                }
                longest = max(count, longest);
            }
        }
        return longest;
    }
};

int main()
{
    return 0;
}