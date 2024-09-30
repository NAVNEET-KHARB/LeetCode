class Solution {
    bool isVowel(char ch){
        return ch == 'a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
public:
    int countOfSubstrings(string word, int k) {
        int n = word.length();
        int ans = 0;
        unordered_map<char,int> vowels;
        vector<int> nextConsonant(n);
        int lastConsonant = n;
        int consonants = 0;
        int left = 0, right = 0;
        for(int i = n-1; i>=0; i--){
            nextConsonant[i] = lastConsonant;
            if(!isVowel(word[i])) lastConsonant = i;
        }
        while(right<n){
            if(isVowel(word[right])){
                vowels[word[right]]++;
            }else consonants++;
            while(left<=right && consonants>k){
                if(isVowel(word[left])){
                    if(--vowels[word[left]] == 0) vowels.erase(word[left]);
                }else consonants--;
                left++;
            }
            while(left<right && consonants == k && vowels.size()==5){
                ans += (nextConsonant[right]-right);
                if(isVowel(word[left])){
                    if(--vowels[word[left]] == 0) vowels.erase(word[left]);
                }else consonants--;
                left++;
            }
            right++;
        }
        return ans;
    }
};