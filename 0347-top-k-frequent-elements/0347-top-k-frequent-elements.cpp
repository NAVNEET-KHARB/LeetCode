class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
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
        vector<int> ans(k);
        int i = 0;
        while(!pq.empty() && k){
            int num = pq.top().second;
            cout<<pq.top().first<<"\t";
            cout<<num<<endl;
            pq.pop();
            ans[i] = num;
            i++;
            k--;
        }
        return ans;
    }
};