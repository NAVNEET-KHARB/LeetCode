class Solution {
    public boolean isSubsequence(String s, String t) {
        int l1 = s.length();
        int l2 = t.length();
        if(l1 == 0) return true;
        if(l1>l2) return false;
        int ind = 0;
        for(int i = 0; i<l2; i++){
            if(s.charAt(ind) == t.charAt(i)){
                ind++;
                if(ind == l1) return true;
            }
        }
        return false;
    }
}