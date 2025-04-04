class Solution {
    public boolean isPal(String s, int start, int end){
        while(start<end){
            if(s.charAt(start++) != s.charAt(end--)) return false;
        }
        return true;
    }
    public void findPart(int ind, int n, String s, List<String> curr, List<List<String>> ans){
        if(ind == n){
            ans.add(new ArrayList<>(curr));
            return;
        }
        for(int i = ind; i<n; i++){
            if(isPal(s,ind,i)){
                curr.add(s.substring(ind,i+1));
                findPart(i+1,n,s,curr,ans);
                curr.remove(curr.size()-1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        int n = s.length();
        List<List<String>> ans = new ArrayList<>();
        List<String> curr = new ArrayList<>();
        findPart(0,n,s,curr,ans);
        return ans;
    }
}