#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 10.48 MB
class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int count = 0;
        for (int num : arr)
        {
            if (num & 1)
                count++;
            else
                count = 0;
            if (count == 3)
                return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}