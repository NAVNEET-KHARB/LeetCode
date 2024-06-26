#include <bits/stdc++.h>
using namespace std;

// Runtime - 159ms || Memory - 89.06 MB
class StockSpanner
{
    stack<pair<int, int>> st;

public:
    StockSpanner() {}

    int next(int price)
    {
        int span = 1;
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

int main()
{
    return 0;
}