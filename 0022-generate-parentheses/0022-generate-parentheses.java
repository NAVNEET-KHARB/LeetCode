class Solution {
    public void generate(int ind, int n, String brack, int openP, int closeP, List<String> ans){
        if(openP == n && closeP == n){
            ans.add(brack);
            return;
        }
        if(brack.charAt(ind) == '('){
            if(openP<n) generate(ind+1,n,brack+"(",openP+1,closeP,ans);
            if(closeP<openP) generate(ind+1,n,brack+")",openP,closeP+1,ans);
        }else{
            if(openP<n) generate(ind+1,n,brack+"(",openP+1,closeP,ans);
            if(closeP<openP) generate(ind+1,n,brack+")",openP,closeP+1,ans);
        }
    }
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        String brack = "(";
        int openP = 1, closeP = 0;
        generate(0,n,brack,openP,closeP,ans);
        return ans;
    }
}