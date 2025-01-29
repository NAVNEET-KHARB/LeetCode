class Solution {
    public boolean isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }
    public String reverseVowels(String s) {
        String vowels = "";
        for(char c : s.toCharArray()){
            if(isVowel(c)) vowels += c;
        }
        StringBuilder ans = new StringBuilder(s);
        int n = ans.length();
        int m = vowels.length();
        for(int i = 0; i<n; i++){
            if(isVowel(ans.charAt(i))){
                ans.setCharAt(i,vowels.charAt(m-1));
                m--;
            }
        }
        return ans.toString();
    }
}