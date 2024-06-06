#include <bits/stdc++.h>
using namespace std;

// Runtime - 33ms || Memory - 23.20 MB
class Solution
{
public:
    bool findSuccessors(vector<int> &hand, int groupSize, int i, int n)
    {
        int next = hand[i] + 1;
        hand[i] = -1;
        int count = 1;
        i += 1;
        while (i < n && count < groupSize)
        {
            if (hand[i] == next)
            {
                next = hand[i] + 1;
                hand[i] = -1;
                count++;
            }
            i++;
        }
        return count == groupSize;
    }
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize)
            return false;
        sort(hand.begin(), hand.end());
        for (int i = 0; i < n; i++)
        {
            if (hand[i] >= 0)
            {
                if (!findSuccessors(hand, groupSize, i, n))
                    return false;
            }
        }
        return true;
    }
};

// Runtime - 46ms || Memory - 30.31 MB
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize)
            return false;
        unordered_map<int, int> mp;
        sort(hand.begin(), hand.end());
        for (int num : hand)
        {
            mp[num]++;
        }
        for (int num : hand)
        {
            if (mp[num] == 0)
                continue;
            for (int i = 0; i < groupSize; i++)
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

int main()
{
    return 0;
}