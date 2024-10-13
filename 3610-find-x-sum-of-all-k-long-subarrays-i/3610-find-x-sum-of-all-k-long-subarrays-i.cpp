class Solution {
    int topKFrequent(vector<int>& arr, int start, int end, int k) {
        vector<int> nums(arr.begin()+start,arr.begin()+end);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        priority_queue<pair<int,int>> pq;
        int num = nums[0];
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == num) cnt++;
            else{
                pq.push({cnt,num});
                num = nums[i];
                cnt = 1;
            }
        }
        pq.push({cnt,num});
        int ans = 0;
        while(!pq.empty() && k){
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
        for(int i = 0; i<=n-k;i++){
            int xSum = topKFrequent(nums,i,i+k,x);
            ans.push_back(xSum);
        }
        return ans;
    }
};