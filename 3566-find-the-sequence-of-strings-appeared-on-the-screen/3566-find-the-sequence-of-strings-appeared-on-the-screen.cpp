class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string typing = "";
        int idx = 0;
        while(idx<target.size()){
            char code = 'a';
            string temp = typing;
            while(code!=target[idx]){
                temp += code;
                ans.push_back(temp);
                temp.erase(temp.begin()+idx);
                code++;
            }
            temp += target[idx];
            ans.push_back(temp);
            typing = temp;
            idx++;
        }
        return ans;
    }
};