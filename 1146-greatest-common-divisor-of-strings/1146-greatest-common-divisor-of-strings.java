class Solution {
    public int gcd(int x, int y){
        if(y==0) return x;
        return gcd(y,x%y);
    }
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1+str2).equals(str2+str1)) return "";
        int n1 = str1.length(), n2 = str2.length();
        int gcdLen = gcd(n1,n2);
        return str1.substring(0,gcdLen);
    }
}