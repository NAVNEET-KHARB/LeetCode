#include <bits/stdc++.h>
using namespace std;

// Runtime - 7ms || Memory - 20.63 MB
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> stk;
        for (int a : asteroids)
        {
            if (a > 0)
            {
                stk.push(a);
            }
            else
            {
                while (!stk.empty() && stk.top() > 0 && stk.top() < -a)
                {
                    stk.pop();
                }
                if (stk.empty() || stk.top() < 0)
                {
                    stk.push(a);
                }
                if (!stk.empty() && stk.top() == -a)
                {
                    stk.pop();
                }
            }
        }
        vector<int> res(stk.size());
        int i = stk.size() - 1;
        while (!stk.empty())
        {
            res[i--] = stk.top();
            stk.pop();
        }
        return res;
    }
};

int main()
{
    return 0;
}