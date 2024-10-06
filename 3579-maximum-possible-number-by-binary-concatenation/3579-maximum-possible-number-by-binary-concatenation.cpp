class Solution {
    string bin(int num){
        string ans = "";
        while(num){
            ans = to_string(num%2) + ans;
            num /= 2;
        }
        return ans;
    }
public:
    int maxGoodNumber(vector<int>& nums) {
        int maxValue = 0;
        sort(nums.begin(), nums.end());
        do {
            string concatenatedBinary = "";
            for (int num : nums) {
                concatenatedBinary += bin(num);
            }
            int decimalValue = stoi(concatenatedBinary, 0, 2);
            maxValue = max(maxValue, decimalValue);
        } while (next_permutation(nums.begin(), nums.end()));
        return maxValue;
    }
};