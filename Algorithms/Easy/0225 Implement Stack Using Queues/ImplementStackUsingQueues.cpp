#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 8.20 MB
class MyStack
{
public:
    queue<int> q;
    MyStack() {}

    void push(int x)
    {
        q.push(x);
        int n = q.size();
        for (int i = 0; i < n - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int r = q.front();
        q.pop();
        return r;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

// Runtime - 5ms || Memory - 8.33 MB
class MyStack
{
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}

    void push(int x)
    {
        q2.push(x);
        while (!(q1.empty()))
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        if (q1.empty())
            return -1;
        int ele = q1.front();
        q1.pop();
        return ele;
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    return 0;
}