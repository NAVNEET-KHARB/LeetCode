class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_set<int> sus;
        sus.insert(k);
        bool kReachable = true;
        while (kReachable) {
            kReachable = false;
            for (auto& it : invocations) {
                int a = it[0];
                int b = it[1];
                if (sus.count(a) && !sus.count(b)) {
                    sus.insert(b);
                    kReachable = true;
                }
            }
        }
        bool flag = false;
        for (auto& it : invocations) {
            int a = it[0];
            int b = it[1];
            if (!sus.count(a) && sus.count(b)) {
                flag = true;
                break;
            }
        }
        vector<int> ans;
        if(flag){
            for (int i = 0; i < n; ++i) {
                ans.push_back(i);
            }
        }else{
            for (int i = 0; i < n; ++i) {
                if (!sus.count(i)) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};