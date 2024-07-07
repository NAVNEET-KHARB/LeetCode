#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 7.07 MB
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int bottlesDrank = numBottles;
        int fullBottles = numBottles;
        int totalBottles = numBottles;
        while (fullBottles)
        {
            fullBottles = totalBottles / numExchange;
            totalBottles = fullBottles + totalBottles % numExchange;
            bottlesDrank += fullBottles;
        }
        return bottlesDrank;
    }
};

int main()
{
    return 0;
}