class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = 0, start = 0;
        for (int n = s.length() - 1; n >= 0; n--) {
            if (s[n] == ' ') {
                if (start == 1)
                    break;
            } else {
                start = 1;
                c++;
            }
        }
        return c;
    }
};