class Solution {
    public void combine(int ind, int n, int[] candidates, int target, List<Integer> curr, HashSet<List<Integer>> ans){
        if(ind == n){
            if(target == 0) ans.add(new ArrayList<>(curr));
            return;
        }
        if(candidates[ind]<=target){
            curr.add(candidates[ind]);
            combine(ind+1,n,candidates,target-candidates[ind],curr,ans);
            curr.remove(curr.size()-1);
        }
        combine(ind+1,n,candidates,target,curr,ans);
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        int n = candidates.length;
        HashSet<List<Integer>> ans = new HashSet<>();
        List<Integer> curr = new ArrayList<>();
        combine(0,n,candidates,target,curr,ans);
        List<List<Integer>> ansArr = new ArrayList<>();
        for(List<Integer> comb : ans) ansArr.add(comb);
        return ansArr;
    }
}