class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        int ans = 0;
        for(int i = 0; i<n-1; i++){
            long long leftSum = prefix[i];
            long long rightSum = prefix[n-1]-leftSum;
            if(leftSum>=rightSum) ans++;
        }
        return ans;
    }
};