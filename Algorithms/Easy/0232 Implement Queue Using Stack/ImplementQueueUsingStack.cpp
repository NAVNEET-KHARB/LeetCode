#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 8.48 MB
class MyQueue
{
    stack<int> input;
    stack<int> output;

public:
    MyQueue() {}

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        if (!(output.empty()))
        {
            int ele = output.top();
            output.pop();
            return ele;
        }
        while (!(input.empty()))
        {
            output.push(input.top());
            input.pop();
        }
        int ele = output.top();
        output.pop();
        return ele;
    }

    int peek()
    {
        if (!(output.empty()))
        {
            return output.top();
        }
        while (!(input.empty()))
        {
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }

    bool empty()
    {
        if (input.empty() && output.empty())
            return true;
        return false;
    }
};

// Runtime - 0ms || Memory - 8.30 MB
class MyQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {}

    void push(int x)
    {
        while (!(s1.empty()))
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!(s2.empty()))
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        if (empty())
            return -1;
        int ele = s1.top();
        s1.pop();
        return ele;
    }

    int peek()
    {
        if (empty())
            return -1;
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    return 0;
}