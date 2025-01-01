class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '1') ones++;
        }
        int ans = 0;
        int zeroes = 0;
        for(int i = 0; i<s.length()-1; i++){
            if(s[i] == '1') ones--;
            else zeroes++;
            ans = max(ans, ones + zeroes);
        }
        return ans;
    }
};