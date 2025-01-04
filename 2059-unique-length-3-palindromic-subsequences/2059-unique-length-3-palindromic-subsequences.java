class Solution {
    public int countPalindromicSubsequence(String s) {
        HashSet<Character> alphas = new HashSet<>();
        for(char c : s.toCharArray()){
            alphas.add(c);
        }
        int ans = 0;
        for(Character alpha : alphas){
            int firstInd = -1;
            int lastInd = 0;
            for(int i = 0; i<s.length(); i++){
                if(s.charAt(i) == alpha){
                    if(firstInd == -1) firstInd = i;
                    else lastInd = i;
                }
            }
            HashSet<Character> midChar = new HashSet<>();
            for(int i = firstInd+1; i<lastInd; i++){
                midChar.add(s.charAt(i));
            }
            ans += midChar.size();
        }
        return ans;
    }
}