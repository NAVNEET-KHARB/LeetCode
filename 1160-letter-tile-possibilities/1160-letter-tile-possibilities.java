class Solution {
    int func(int[] countChar){
        int total = 0;
        for(int i = 0; i<26; i++){
            if(countChar[i] == 0) continue;
            total++;
            countChar[i]--;
            total += func(countChar);
            countChar[i]++;
        }
        return total;
    }
    public int numTilePossibilities(String tiles) {
        int[] countChar = new int[26];
        for(char c : tiles.toCharArray()) countChar[c-'A']++;
        return func(countChar);
    }
}