#include <bits/stdc++.h>
using namespace std;

// Runtime - 106ms || Memory - 53.23 MB
class Solution
{
public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n % k)
            return false;
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        for (int num : nums)
        {
            mp[num]++;
        }
        for (int num : nums)
        {
            if (mp[num] == 0)
                continue;
            for (int i = 0; i < k; i++)
            {
                if (mp[num + i] == 0)
                    return false;
                else
                    mp[num + i]--;
            }
        }
        return true;
    }
};

// Runtime - 147ms || Memory - 53.39 MB
class Solution
{
public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n % k)
            return false;
        map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }
        while (!freq.empty())
        {
            int currentVal = freq.begin()->first;
            for (int i = 0; i < k; i++)
            {
                if (freq[currentVal + i] == 0)
                {
                    return false;
                }
                freq[currentVal + i]--;
                if (freq[currentVal + i] < 1)
                {
                    freq.erase(currentVal + i);
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}