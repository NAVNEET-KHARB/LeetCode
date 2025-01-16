class Solution {
    public String mergeAlternately(String word1, String word2) {
        int n1 = word1.length(), n2 = word2.length();
        int i = 0, j = 0;
        String ans = "";
        while(i<n1 && j<n2){
            ans += word1.charAt(i);
            i++;
            ans += word2.charAt(j);
            j++;
        }
        while(i<n1){
            ans += word1.charAt(i);
            i++;
        }
        while(j<n2){
            ans += word2.charAt(j);
            j++;
        }
        return ans;
    }
}