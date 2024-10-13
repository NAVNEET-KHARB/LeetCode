class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int num: nums){
            mpp[num]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it : mpp){
            pq.push({it.second,it.first});
        }
        vector<int> ans(k);
        int i = 0;
        while(!pq.empty() && k){
            int num = pq.top().second;
            pq.pop();
            ans[i] = num;
            i++;
            k--;
        }
        return ans;
    }
};