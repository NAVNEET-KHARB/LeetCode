class Solution {
    int topKFrequent(vector<int>& arr, int start, int end, int k) {
        vector<int> nums(arr.begin() + start, arr.begin() + end);
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }
        int ans = 0;
        while (!pq.empty() && k) {
            int num = (pq.top().first * pq.top().second);
            pq.pop();
            ans += num;
            k--;
        }
        return ans;
    }

public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i <= n - k; i++) {
            int xSum = topKFrequent(nums, i, i + k, x);
            ans.push_back(xSum);
        }
        return ans;
    }
};