class Solution {
    bool match(vector<int> s1Arr, vector<int> s2Arr){
        for(int i = 0; i<26; i++){
            if(s1Arr[i]!=s2Arr[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        vector<int> s1Arr(26);
        vector<int> s2Arr(26);
        for(int i = 0; i<s1.length(); i++){
            s1Arr[s1[i]-'a']++;
            s2Arr[s2[i]-'a']++;
        }
        for(int i = 0; i<s2.length()-s1.length(); i++){
            if(match(s1Arr,s2Arr)) return true;
            s2Arr[s2[i+s1.length()]-'a']++;
            s2Arr[s2[i]-'a']--;
        }
        return match(s1Arr,s2Arr);
    }
};