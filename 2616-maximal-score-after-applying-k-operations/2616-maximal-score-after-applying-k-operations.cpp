class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int num : nums) pq.push(num);
        long long ans = 0;
        while(k){
            int num = pq.top();
            pq.pop();
            ans += num;
            (num%3 == 0)?pq.push(num/3):pq.push(num/3 + 1);
            k--;
        }
        return ans;
    }
};