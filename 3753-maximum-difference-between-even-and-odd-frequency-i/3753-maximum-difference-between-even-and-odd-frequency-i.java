class Solution {
    public int maxDifference(String s) {
        int[] chars = new int[26];
        for(char c : s.toCharArray()){
            chars[c-'a']++;
        }
        int odd = 0, even = 100;
        for(int i = 0; i<26; i++){
            if(chars[i] % 2 != 0){
                odd = Math.max(odd,chars[i]);
            }else{
                if(chars[i] != 0) even = Math.min(even,chars[i]);
            }
        }
        return odd-even;
    }
}