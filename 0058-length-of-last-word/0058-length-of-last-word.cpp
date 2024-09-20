class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int end = n-1;
        while(end>=0 && s[end] == ' ') end--;
        int start = end;
        while(end>=0 && s[end] != ' ') end--;
        return start - end;
    }
};