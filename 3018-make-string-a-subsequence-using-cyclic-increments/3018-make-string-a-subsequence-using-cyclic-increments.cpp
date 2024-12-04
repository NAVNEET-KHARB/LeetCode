class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int charsMatched = 0;
        int n = str1.length(), m = str2.length();
        for(int i = 0; i<n && charsMatched<m; i++){
            if((str1[i] == str2[charsMatched])||((str1[i]-'a'+1)%26 == (str2[charsMatched]-'a'))) charsMatched++;
        }
        return (charsMatched == m);
    }
};