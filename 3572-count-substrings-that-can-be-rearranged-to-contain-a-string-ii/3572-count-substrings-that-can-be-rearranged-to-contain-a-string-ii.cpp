class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> words(26,0);
        for(char c : word2) words[c-'a']++;
        vector<int> count(26,0);
        int start = 0, k = word2.length();
        long long ans = 0;
        for(int i = 0; i<word1.length(); i++){
            char curr = word1[i];
            if(words[curr-'a']>0){
                if(count[curr-'a']<words[curr-'a']) k--;
            }
            count[curr-'a']++;
            while(k==0){
                ans += word1.length()-i;
                char prev = word1[start];
                count[prev-'a']--;
                if(words[prev-'a']>0 && count[prev-'a']<words[prev-'a']) k++;
                start++;
            }
        }
        return ans;
    }
};