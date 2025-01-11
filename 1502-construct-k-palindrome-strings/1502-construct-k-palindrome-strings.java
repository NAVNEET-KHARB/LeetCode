class Solution {
    public boolean canConstruct(String s, int k) {
        if(s.length()<k) return false;
        if(s.length() == k) return true;
        int [] freq = new int[26];
        int oddCount = 0;
        for(char ch : s.toCharArray()){
            freq[ch-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(freq[i]%2==1) oddCount++;
        }
        return (oddCount<=k);
    }
}