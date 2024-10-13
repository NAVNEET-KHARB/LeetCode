class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        for(int i = 0; i<n; i++){
            int bit = 0;
            while(nums[i]&(1<<bit)) bit++;
            if(nums[i]&1) ans[i] = nums[i] ^ (1<<(bit-1));
        }
        return ans;
    }
};