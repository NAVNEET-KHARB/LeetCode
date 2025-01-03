class Solution {
    public boolean isPalindrome(String s) {
        String temp = "";
        for(char c : s.toCharArray()){
            if(Character.isLetterOrDigit(c)) temp += Character.toLowerCase(c);
        }
        int n = temp.length();
        for(int i = 0; i<n/2; i++){
            if(temp.charAt(i) != temp.charAt(n-i-1)) return false;
        }
        return true;
    }
}