class Solution {
    bool isVowel(char ch){
        return ch == 'a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        long long ans = 0;
        unordered_map<char,int> vowels;
        vector<int> nextConsonant(n);
        int consonants = 0;
        int lastConsonant = n;
        for(int i = n-1; i>=0; i--){
            nextConsonant[i] = lastConsonant;
            if(!isVowel(word[i])) lastConsonant = i;
        }
        int right = 0;
        int left = 0;
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
            while(left<right && vowels.size() == 5 &&consonants == k){
                ans += (nextConsonant[right] - right);
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