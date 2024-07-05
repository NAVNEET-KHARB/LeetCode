#include <bits/stdc++.h>
using namespace std;

// Runtime - 4ms || Memory - 12.58 MB
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        if (n == 0 || m == 0)
            return {};
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        vector<int> ans;
        while (i < n && j < m)
        {
            if (nums1[i] < nums2[j])
            {
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}