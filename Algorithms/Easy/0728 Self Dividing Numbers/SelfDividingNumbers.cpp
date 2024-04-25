#include <bits/stdc++.h>
using namespace std;

// Solution 1
// Runtime - 0ms | Memory - 7.66 MB
class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            int x = i;
            int rem;
            int flag = 0;
            while (x)
            {
                rem = x % 10;
                if (rem == 0)
                {
                    flag = 1;
                    break;
                }
                if (i % rem != 0)
                {
                    flag = 1;
                    break;
                }
                x /= 10;
            }
            if (flag == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Solution 2
// Runtime - 3ms | Memory -7.54 MB
class Solution
{
public:
    bool selfDivisor(int num)
    {
        int numCopy = num;
        while (num)
        {
            int digit = num % 10;
            if (digit == 0 || numCopy % digit != 0)
                return false;
            num /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            if (selfDivisor(i))
                ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
    return 0;
}