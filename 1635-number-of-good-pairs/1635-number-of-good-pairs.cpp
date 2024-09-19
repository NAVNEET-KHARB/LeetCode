class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> freq(101,0);
        int count = 0;
        for(int num : nums){
            count += freq[num];
            freq[num]++;
        }
        return count;
    }
};