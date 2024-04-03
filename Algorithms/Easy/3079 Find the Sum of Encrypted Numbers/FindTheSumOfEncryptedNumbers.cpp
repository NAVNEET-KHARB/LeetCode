#include <bits/stdc++.h>
using namespace std;

// Runtime - 7ms | Memory - 27.6 MB
class Solution
{
public:
    int encrypt(int n)
    {
        int largest = 0;
        string s = to_string(n);
        for (auto it : s)
        {
            if ((it - '0') > largest)
            {
                largest = it - '0';
            }
        }
        for (auto &it : s)
        {
            it = largest + '0';
        }
        return stoi(s);
    }
    int sumOfEncryptedInt(vector<int> &nums)
    {
        int sum = 0;
        for (auto it : nums)
        {
            int dig = encrypt(it);
            sum += dig;
        }
        return sum;
    }
};

int main()
{
    return 0;
}