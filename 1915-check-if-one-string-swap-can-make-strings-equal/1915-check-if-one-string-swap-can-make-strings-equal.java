class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        int cnt = 0, ind1 = 0, ind2 = 0;
        for(int i = 0; i<s1.length();i++){
            if(s1.charAt(i) != s2.charAt(i)){
                cnt++;
                if(cnt>2) return false;
                else if(cnt==1) ind1 = i;
                else ind2 = i;
            }
        }
        return (s1.charAt(ind1)==s2.charAt(ind2) && s1.charAt(ind2)==s2.charAt(ind1));
    }
}