#include <bits/stdc++.h>
using namespace std;

// Runtime - 60ms || Memory - 42.51 MB
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long ans = 0;
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
                ans =
                    (ans + static_cast<long>(ele.second) * left * right) % MOD;
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
            ans = (ans + static_cast<long>(ele.second) * left * right) % MOD;
        }
        return ans;
    }
};

int main()
{
    return 0;
}