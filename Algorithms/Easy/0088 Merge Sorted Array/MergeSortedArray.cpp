#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 10.94 MB
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;
        else if (m == 0)
        {
            int i = 0;
            for (auto it : nums2)
            {
                nums1[i++] = it;
            }
            return;
        }
        for (int i = m; i < n + m; i++)
        {
            nums1[i] = nums2[i - m];
        }
        sort(nums1.begin(), nums1.end());
    }
};

// Runtime - 2ms || Memory - 10.91 MB
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;
        else if (m == 0)
        {
            int i = 0;
            for (auto it : nums2)
            {
                nums1[i++] = it;
            }
            return;
        }
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

int main()
{
    return 0;
}