class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        generate(0, 0, "", n, ans);
        return ans;        
    }
    private void generate(int openP, int closeP, String brack, int n, List<String> ans) {
        if (openP == closeP && openP + closeP == n * 2) {
            ans.add(brack);
            return;
        }
        if (openP < n) {
            generate(openP + 1, closeP, brack + "(", n, ans);
        }
        if (closeP < openP) {
            generate(openP, closeP + 1, brack + ")", n, ans);
        }
    }    
}