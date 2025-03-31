class Solution {
    public void combine(int num, int k, int n, List<Integer> curr, List<List<Integer>> ans){
        if(k == 0){
            if(n == 0) ans.add(new ArrayList<>(curr));
            return;
        }
        if(k<0 || n<0 || num>9) return;
        curr.add(num);
        combine(num+1,k-1,n-num,curr,ans);
        curr.remove(curr.size()-1);
        combine(num+1,k,n,curr,ans);
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        combine(1,k,n,curr,ans);
        return ans;
    }
}