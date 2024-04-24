#include <bits/stdc++.h>
using namespace std;

// Runtime - 44ms || Memory - 21.41 MB
class Solution
{
public:
    long long hours(vector<int> &piles, int hourlyRate)
    {
        long long totalHrs = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++)
        {
            totalHrs += ceil((double)piles[i] / (double)hourlyRate);
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        long long ans = high;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long totalHours = hours(piles, mid);
            if (totalHours <= h)
            {
                high = mid - 1;
                if (mid < ans)
                {
                    ans = mid;
                }
            }
            else
                low = mid + 1;
        }
        return (int)ans;
    }
};

// Runtime - 49ms || Memory - 22.19 MB
class Solution
{
public:
    long long hours(vector<int> &piles, int n, int hourlyRate)
    {
        long long totalHrs = 0;
        for (int i = 0; i < n; i++)
        {
            totalHrs += ceil((double)piles[i] / (double)hourlyRate);
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int low = 1, high = piles[n - 1];
        long long ans = high;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long totalHours = hours(piles, n, mid);
            if (totalHours <= h)
            {
                high = mid - 1;
                if (mid < ans)
                {
                    ans = mid;
                }
            }
            else
                low = mid + 1;
        }
        return (int)ans;
    }
};

int main()
{
    return 0;
}