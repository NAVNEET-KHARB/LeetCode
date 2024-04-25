#include <bits/stdc++.h>
using namespace std;

// Runtime - 102ms || Memory - 68.84 MB
class Solution
{
public:
    bool isBoquetPossible(vector<int> &bloomDay, int day, int m, int k)
    {
        int count = 0, boquet = 0;
        for (int bloom : bloomDay)
        {
            if (bloom <= day)
                count++;
            else
            {
                boquet += (count / k);
                count = 0;
            }
        }
        boquet += (count / k);
        if (boquet >= m)
            return true;
        return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int ans = -1;
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isBoquetPossible(bloomDay, mid, m, k) == true)
            {
                high = mid - 1;
                ans = mid;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

// Runtime - 133ms || Memory - 69.02 MB
class Solution
{
public:
    bool isBoquetPossible(vector<int> &bloomDay, int day, int m, int k)
    {
        int count = 0, boquet = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= day)
                count++;
            else
            {
                boquet += (count / k);
                count = 0;
            }
        }
        boquet += (count / k);
        if (boquet >= m)
            return true;
        return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int ans = -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isBoquetPossible(bloomDay, mid, m, k) == true)
            {
                high = mid - 1;
                if (ans == -1)
                    ans = mid;
                else if (ans > mid)
                    ans = mid;
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