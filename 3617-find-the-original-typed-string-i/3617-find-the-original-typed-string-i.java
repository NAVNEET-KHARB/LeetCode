class Solution {
    public int possibleStringCount(String word) {
        int n = word.length();
        int ans = 1;
        for(int i = 1; i<n; i++){
            if(word.charAt(i) == word.charAt(i-1)) ans++;
        }
        return ans;
    }
}