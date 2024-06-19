#include <bits/stdc++.h>
using namespace std;

// Runtime - 12ms || Memory - 21.16 MB
class MinStack
{
    stack<long> st;
    long mini;

public:
    MinStack()
    {
        mini = INT_MAX;
    }

    void push(int val)
    {
        long value = val;
        if (st.empty())
        {
            mini = value;
            st.push(value);
        }
        else
        {
            if (val < mini)
            {
                st.push(2 * value - mini);
                mini = value;
            }
            else
            {
                st.push(value);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long el = st.top();
        st.pop();
        if (el < mini)
        {
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;
        long el = st.top();
        if (el < mini)
            return mini;
        return el;
    }

    int getMin()
    {
        if (!st.empty())
        {
            return mini;
        }
        return -1;
    }
};

// Runtime - 16ms || Memory - 21.32 MB
class MinStack
{
    stack<pair<long, long>> st;

public:
    MinStack() {}

    void push(int val)
    {
        long mini;
        if (st.empty())
        {
            mini = val;
        }
        else
        {
            mini = min(st.top().second, (long)val);
        }
        st.push({val, mini});
    }

    void pop()
    {
        if (!st.empty())
        {
            st.pop();
        }
    }

    int top()
    {
        if (!st.empty())
        {
            return st.top().first;
        }
        return -1;
    }

    int getMin()
    {
        if (!st.empty())
        {
            return st.top().second;
        }
        return -1;
    }
};

int main()
{
    return 0;
}