class Solution {
public:
    long long minimumSteps(string s) {
        int wPos = 0;
        long long swaps = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                swaps += i - wPos;
                wPos++;
            }
        }
        return swaps;
    }
};