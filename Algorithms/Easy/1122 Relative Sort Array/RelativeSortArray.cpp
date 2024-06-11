#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms || Memory - 10.05 MB
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        map<int, int> eles;
        int n = arr1.size();
        int m = arr2.size();
        if (n == 1 || m == 1)
            return arr1;
        for (int i = 0; i < n; i++)
        {
            eles[arr1[i]]++;
        }
        int i = 0;
        for (int j = 0; j < m; j++)
        {
            int num = arr2[j];
            while (i < n && eles[num])
            {
                arr1[i] = num;
                eles[num]--;
                i++;
            }
        }
        for (auto &rec : eles)
        {
            int num = rec.first;
            while (i < n && eles[num])
            {
                arr1[i] = num;
                eles[num]--;
                i++;
            }
        }
        return arr1;
    }
};

int main()
{
    return 0;
}