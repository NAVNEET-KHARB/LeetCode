#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 25.01 MB
class Solution
{
public:
    double minimumAverage(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        double minAverage = DBL_MAX;
        while (!nums.empty())
        {
            double minEL = nums.front();
            double maxEL = nums.back();
            double avg = (minEL + maxEL) / 2.0;
            minAverage = min(minAverage, avg);
            nums.erase(nums.begin());
            if (!nums.empty())
            {
                nums.pop_back();
            }
        }
        return minAverage;
    }
};

int main()
{
    return 0;
}