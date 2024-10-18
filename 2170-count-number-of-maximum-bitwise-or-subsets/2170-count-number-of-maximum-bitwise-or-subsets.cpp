class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;
        for(int num : nums) maxOR |= num;
        int totalSubsets = 1<<n;
        int ans = 0;
        for(int subsetMask = 0; subsetMask<totalSubsets; subsetMask++){
            int currOR = 0;
            for(int i = 0; i<n; i++){
                if(((subsetMask>>i)&1) == 1){
                    currOR |= nums[i];
                }
            }
            if(currOR == maxOR) ans++;
        }
        return ans;
    }
};