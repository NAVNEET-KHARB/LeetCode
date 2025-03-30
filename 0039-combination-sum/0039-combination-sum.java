class Solution {
    public void combine(int ind, int n, int[] candidates, int target, List<Integer> curr, List<List<Integer>> ans){
        if(ind == n){
            if(target == 0) ans.add(new ArrayList<>(curr));
            return;
        }
        if(candidates[ind]<=target){
            curr.add(candidates[ind]);
            combine(ind,n,candidates,target-candidates[ind],curr,ans);
            curr.remove(curr.size()-1);
        }
        combine(ind+1,n,candidates,target,curr,ans);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        int n = candidates.length;
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        combine(0,n,candidates,target,curr,ans);
        return ans;
    }
}