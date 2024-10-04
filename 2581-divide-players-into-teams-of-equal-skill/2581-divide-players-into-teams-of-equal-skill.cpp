class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int totalSkill = 0;
        unordered_map<int,int> skillCount;
        for(int sk : skill){
            totalSkill += sk;
            skillCount[sk]++;
        }
        if(totalSkill%(n/2) != 0) return -1;
        int targetSkill = totalSkill/(n/2);
        long long chemistry = 0;
        for(int i = 0; i<n; i++){
            int reqSkill = targetSkill-skill[i];
            if(!skillCount[reqSkill]) return -1;
            chemistry += (long long)reqSkill * (long long)skill[i];
            skillCount[reqSkill]--;
        }
        return chemistry/2;
    }
};