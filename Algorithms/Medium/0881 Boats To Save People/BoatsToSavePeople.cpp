#include <bits/stdc++.h>
using namespace std;

// Runtime - 58ms || Runtime - 45.44 MB
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int boats = 0;
        sort(people.begin(), people.end());
        int n = people.size();
        for (int l = 0, r = n - 1; l <= r; r--)
        {
            boats++;
            if (people[l] <= limit - people[r])
                l++;
        }
        return boats;
    }
};

int main()
{
    return 0;
}