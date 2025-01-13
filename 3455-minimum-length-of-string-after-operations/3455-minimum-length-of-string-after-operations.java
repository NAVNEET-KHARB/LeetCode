class Solution {
    public int minimumLength(String s) {
        int n = s.length();
        int[] freq = new int[26];
        for(int i = 0; i<n; i++){
            freq[s.charAt(i)-'a']++;
            if(freq[s.charAt(i)-'a'] == 3) freq[s.charAt(i)-'a']-=2;
        }
        int ans = 0;
        for(int i = 0; i<26; i++){
            ans += freq[i];
        }
        return ans;
    }
}