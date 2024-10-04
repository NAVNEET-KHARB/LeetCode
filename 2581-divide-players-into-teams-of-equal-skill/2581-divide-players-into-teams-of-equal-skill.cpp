class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n = skill.size();
        int targetSkill = skill[0] + skill[n-1];
        long long chemistry = 0;
        for(int i = 0; i<n/2; i++){
            int currentSkill = skill[i] + skill[n-i-1];
            if(currentSkill != targetSkill) return -1;
            chemistry += (long long)skill[i] * (long long)skill[n-i-1];
        }
        return chemistry;
    }
};