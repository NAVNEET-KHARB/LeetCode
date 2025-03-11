class Solution {
    private boolean isEli(int[] freq){
        return freq[0]>0 && freq[1]>0 && freq[2]>0;
    }
    public int numberOfSubstrings(String s) {
        int n = s.length();
        int[] freq = new int[3];
        int left = 0, right = 0, ans = 0;
        while(right<n){
            char curr = s.charAt(right);
            freq[curr- 'a']++;
            while(isEli(freq)){
                ans += n - right;
                char leftChar = s.charAt(left);
                freq[leftChar - 'a']--;
                left++;
            }
            right++;
        }
        return ans;
    }
}