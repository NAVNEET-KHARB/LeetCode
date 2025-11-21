class Solution {
    public int countPalindromicSubsequence(String s) {
        int[] firstInd = new int[26];
        int[] lastInd = new int[26];
        Arrays.fill(firstInd,-1);
        for(int i = 0; i<s.length(); i++){
            int alpha = s.charAt(i)-'a';
            if(firstInd[alpha] == -1) firstInd[alpha] = i;
            else lastInd[alpha] = i;
        }
        int ans = 0;
        for(int i = 0; i<26; i++){
            HashSet<Character> midChar = new HashSet<>();
            for(int j = firstInd[i]+1; j<lastInd[i]; j++){
                midChar.add(s.charAt(j));
            }
            ans += midChar.size();
        }
        return ans;
    }
}