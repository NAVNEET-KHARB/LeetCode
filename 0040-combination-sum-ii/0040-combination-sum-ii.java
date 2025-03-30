class Solution {
    public void combine(int ind, int n, int[] candidates, int target, List<Integer> curr, List<List<Integer>> ans){
        if(target == 0) {
            if(!ans.contains(curr)) ans.add(new ArrayList<>(curr));
            return;
        }
        for(int i = ind; i < n; i++){
            if(i > ind && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            curr.add(candidates[i]);
            combine(i + 1, n, candidates, target - candidates[i], curr, ans);
            curr.remove(curr.size() - 1);
        }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        int n = candidates.length;
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        combine(0,n,candidates,target,curr,ans);
        return ans;
    }
}