#include <bits/stdc++.h>
using namespace std;

// Runtime - 118ms || Memory - 49.24 MB
class Solution
{
public:
    void merge(vector<int> &arr, int start, int end, int &count, vector<int> &temp)
    {
        int mid = start + (end - start) / 2;
        int i = start, j = mid + 1, k = start;

        while (i <= mid && j <= end)
        {
            if (arr[i] > (long long)2 * arr[j])
            {
                count += (mid - i + 1);
                j++;
            }
            else
            {
                i++;
            }
        }

        i = start;
        j = mid + 1;

        while (i <= mid && j <= end)
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid)
        {
            temp[k++] = arr[i++];
        }
        while (j <= end)
        {
            temp[k++] = arr[j++];
        }

        while (start <= end)
        {
            arr[start] = temp[start];
            start++;
        }
    }

    void mergesort(vector<int> &nums, int start, int end, int &count, vector<int> &temp)
    {
        if (start >= end)
        {
            return;
        }

        int mid = start + (end - start) / 2;
        mergesort(nums, start, mid, count, temp);
        mergesort(nums, mid + 1, end, count, temp);
        merge(nums, start, end, count, temp);
    }

    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0, start = 0, end = n - 1;
        vector<int> temp(n);
        mergesort(nums, start, end, count, temp);
        return count;
    }
};

// Runtime - 551ms || Memory - 235.67 MB
class Solution
{
public:
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (arr[left] > arr[right])
            {
                temp.push_back(arr[right]);
                right++;
            }
            else
            {
                temp.push_back(arr[left]);
                left++;
            }
        }
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }
    int countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int cnt = 0;
        int right = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && (long long)arr[i] > 2 * (long long)arr[right])
                right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    int mergeSort(vector<int> &arr, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main()
{
    return 0;
}