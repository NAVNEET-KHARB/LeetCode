class Solution {
    long long calculateGCD(const vector<int>& nums) {
        long long gcdVal = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            gcdVal = gcd(gcdVal, nums[i]);
        }
        return gcdVal;
    }
    long long calculateLCM(const vector<int>& nums) {
        long long lcmVal = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            lcmVal = (lcmVal * nums[i]) / gcd(lcmVal, (long long)nums[i]);
        }
        return lcmVal;
    }
public:
    long long maxScore(vector<int>& nums) {
        long long totalGCD = calculateGCD(nums);
        long long totalLCM = calculateLCM(nums);
        long long ans = totalGCD*totalLCM;
        for(int i = 0; i<nums.size(); i++){
            vector<int> temp(nums.begin(), nums.end());
            temp.erase(temp.begin() + i);
            long long tempGCD = calculateGCD(temp);
            long long tempLCM = calculateLCM(temp);
            ans = max(ans, tempGCD * tempLCM);
        }
        return ans;
    }
};