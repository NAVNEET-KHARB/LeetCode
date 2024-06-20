#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 12.26 MB
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        unordered_map<int, int> map;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            if (st.empty())
                map[nums2[i]] = -1;
            else
                map[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int> res;
        for (auto it : nums1)
        {
            res.push_back(map[it]);
        }
        return res;
    }
};

// Runtime - 9ms || Memory - 10.68 MB
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> nge(n);
        for (int i = 0; i < n; i++)
        {
            int ans = -1;
            for (int j = 0; j < m; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    for (int k = j; k < m; k++)
                    {
                        if (nums2[k] > nums2[j])
                        {
                            ans = nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
            nge[i] = ans;
        }
        return nge;
    }
};

int main()
{
    return 0;
}