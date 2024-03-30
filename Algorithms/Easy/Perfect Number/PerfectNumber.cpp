#include <bits/stdc++.h>
using namespace std;
// Way 1
// 1042 ms runtime 7.09 MB memory
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num <= 0)
            return false;
        int sum = 0;
        for (int i = 1; i <= num / 2; i++)
        {
            if (num % i == 0)
            {
                sum += i;
            }
        }
        return (num == sum);
    }
};

// Way 2
// 3ms runtime 7.21 MB memory
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num <= 0)
            return false;
        int sum = 0;
        for (int i = 1; i < sqrt(num); i++)
        {
            if (num % i == 0)
                sum += i;
        }
        for (int i = sqrt(num); i > 1; i--)
        {
            if (num % i == 0)
                sum += num / i;
        }
        return (num == sum);
    }
};
int main()
{
    return 0;
}