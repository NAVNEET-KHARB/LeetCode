class Solution {
    public boolean checkValidString(String s) {
        int openBrac = 0;
        int closeBrac = 0;
        int size = s.length();
        for (int i = 0; i < size; i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '*') openBrac++;
            else openBrac--;
            if (s.charAt(size - i - 1) == ')' || s.charAt(size - i -1) == '*') closeBrac++;
            else closeBrac--;
            if (openBrac < 0 || closeBrac < 0) return false;
        }
        return true;
    }
}