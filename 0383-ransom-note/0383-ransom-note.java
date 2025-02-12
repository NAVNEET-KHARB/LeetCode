class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] ransom = new int[26];
        int[] mag = new int[26];
        for(char c : ransomNote.toCharArray()){
            ransom[c-'a']++;
        }
        for(char c : magazine.toCharArray()){
            mag[c-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(ransom[i]>mag[i]) return false;
        }
        return true;
    }
}