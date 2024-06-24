#include <bits/stdc++.h>
using namespace std;

// Runtime - 10ms || Memory - 13.11 MB
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        long long sMax = 0;
        long long sMin = 0;
        stack<pair<int, int>> moStM;
        stack<pair<int, int>> moStS;
        for (int i = 0; i < n; i++)
        {
            while (!moStS.empty() && nums[i] < moStS.top().second)
            {
                auto ele = moStS.top();
                moStS.pop();
                int left = ele.first + 1;
                if (!moStS.empty())
                {
                    left = ele.first - moStS.top().first;
                }
                int right = i - ele.first;
                sMin = (sMin + static_cast<long>(ele.second) * left * right);
            }
            moStS.push({i, nums[i]});
            while (!moStM.empty() && nums[i] > moStM.top().second)
            {
                auto ele = moStM.top();
                moStM.pop();
                int left = ele.first + 1;
                if (!moStM.empty())
                {
                    left = ele.first - moStM.top().first;
                }
                int right = i - ele.first;
                sMax = (sMax + static_cast<long>(ele.second) * left * right);
            }
            moStM.push({i, nums[i]});
        }
        while (!moStS.empty())
        {
            auto ele = moStS.top();
            moStS.pop();
            int left = ele.first + 1;
            if (!moStS.empty())
            {
                left = ele.first - moStS.top().first;
            }
            int right = n - ele.first;
            sMin = (sMin + static_cast<long>(ele.second) * left * right);
        }
        while (!moStM.empty())
        {
            auto ele = moStM.top();
            moStM.pop();
            int left = ele.first + 1;
            if (!moStM.empty())
            {
                left = ele.first - moStM.top().first;
            }
            int right = n - ele.first;
            sMax = (sMax + static_cast<long>(ele.second) * left * right);
        }
        return sMax - sMin;
    }
};

// Runtime - 15ms || Memory - 13.08 MB
class Solution
{
public:
    long long sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        long long ans = 0;
        stack<pair<int, int>> moSt;
        for (int i = 0; i < n; i++)
        {
            while (!moSt.empty() && arr[i] < moSt.top().second)
            {
                auto ele = moSt.top();
                moSt.pop();
                int left = ele.first + 1;
                if (!moSt.empty())
                {
                    left = ele.first - moSt.top().first;
                }
                int right = i - ele.first;
                ans = (ans + static_cast<long>(ele.second) * left * right);
            }
            moSt.push({i, arr[i]});
        }
        while (!moSt.empty())
        {
            auto ele = moSt.top();
            moSt.pop();
            int left = ele.first + 1;
            if (!moSt.empty())
            {
                left = ele.first - moSt.top().first;
            }
            int right = n - ele.first;
            ans = (ans + static_cast<long>(ele.second) * left * right);
        }
        return ans;
    }

    long long sumSubarrayMaxs(vector<int> &arr)
    {
        int n = arr.size();
        long long ans = 0;
        stack<pair<int, int>> moSt;
        for (int i = 0; i < n; i++)
        {
            while (!moSt.empty() && arr[i] > moSt.top().second)
            {
                auto ele = moSt.top();
                moSt.pop();
                int left = ele.first + 1;
                if (!moSt.empty())
                {
                    left = ele.first - moSt.top().first;
                }
                int right = i - ele.first;
                ans = (ans + static_cast<long>(ele.second) * left * right);
            }
            moSt.push({i, arr[i]});
        }
        while (!moSt.empty())
        {
            auto ele = moSt.top();
            moSt.pop();
            int left = ele.first + 1;
            if (!moSt.empty())
            {
                left = ele.first - moSt.top().first;
            }
            int right = n - ele.first;
            ans = (ans + static_cast<long>(ele.second) * left * right);
        }
        return ans;
    }
    long long subArrayRanges(vector<int> &nums)
    {
        long long sumMax = sumSubarrayMaxs(nums);
        long long sumMin = sumSubarrayMins(nums);
        return sumMax - sumMin;
    }
};

int main()
{
    return 0;
}