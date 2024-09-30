class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.size()<k){
            string appe = "";
            for(int i = 0; i<word.size(); i++){
                if(word[i] == 'z') appe += 'a';
                else appe += char(int(word[i])+1);
            }
            word += appe;
        }
        return word[k-1];
    }
};