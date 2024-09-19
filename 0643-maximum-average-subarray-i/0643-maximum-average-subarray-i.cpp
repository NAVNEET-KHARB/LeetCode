class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, start = 0;
        double ans = DBL_MIN;
        for(int i = 0; i<nums.size();i++){
            sum += nums[i];
            if(i>=k-1){
                double average = (double)sum/k;
                if(ans == DBL_MIN) ans = average;
                else ans = max(ans,average);
                sum -= nums[start];
                start++;
            }
        }
        return ans;
    }
};