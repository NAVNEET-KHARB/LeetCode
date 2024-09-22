class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int> wordMap;
        for(auto word: bannedWords) wordMap[word]++;
        int words = 0;
        for(auto msg : message){
            if(wordMap[msg]) words++;
        }
        return words>=2?true:false;
    }
};