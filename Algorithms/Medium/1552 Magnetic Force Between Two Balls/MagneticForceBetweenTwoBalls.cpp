#include <bits/stdc++.h>
using namespace std;

// Runtime - 122ms || Memory - 61.42 MB
class Solution
{
public:
    bool canWePlace(vector<int> &position, int dist, int balls)
    {
        int currBalls = 1;
        int lastBall = position[0];
        for (int i = 1; i < position.size(); i++)
        {
            if (position[i] - lastBall >= dist)
            {
                currBalls++;
                lastBall = position[i];
            }
            if (currBalls == balls)
                return true;
        }
        return false;
    }
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int low = 1, high = position[position.size() - 1] - position[0];
        if (m == 2)
            return high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canWePlace(position, mid, m) == true)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return high;
    }
};

int main()
{
    return 0;
}