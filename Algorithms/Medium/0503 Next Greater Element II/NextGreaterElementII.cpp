#include <bits/stdc++.h>
using namespace std;

// Runtime - 19ms || Memory - 26.59 MB
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }
            if (!st.empty() && i < n)
                nge[i] = st.top();
            st.push(nums[i % n]);
        }
        return nge;
    }
};

int main()
{
    return 0;
}