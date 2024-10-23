class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        if (target.size() == 0) return ans;
        string temp = "";
        for (int idx = 0; idx < target.size(); idx++) {
            char ch1 = target[idx];
            for (char ch2 = 'a'; ch2 <= ch1; ++ch2) {
                ans.push_back(temp + ch2);
            }
            temp += ch1;
        }
        return ans;
    }
};