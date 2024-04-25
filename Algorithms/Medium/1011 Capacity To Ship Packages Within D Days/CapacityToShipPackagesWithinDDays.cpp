#include <bits/stdc++.h>
using namespace std;

// Runtime - 34ms || Memory - 33.31 MB
class Solution
{
public:
    int daysRequired(vector<int> &weights, int capacity)
    {
        int days = 1;
        int load = 0;
        for (int weight : weights)
        {
            if (load + weight > capacity)
            {
                days++;
                load = weight;
            }
            else
                load += weight;
        }
        return days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (daysRequired(weights, mid) <= days)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

int main()
{
    return 0;
}