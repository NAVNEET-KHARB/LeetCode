class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if(pattern.length()!=words.length) return false;
        HashMap<Character,String> charWord = new HashMap<>();
        HashMap<String,Character> wordChar = new HashMap<>();
        for(int i = 0; i<pattern.length(); i++){
            if(charWord.containsKey(pattern.charAt(i))){
                if(!charWord.get(pattern.charAt(i)).equals(words[i])) return false;
            }else{
                if(wordChar.containsKey(words[i])){
                    if(wordChar.get(words[i]) != pattern.charAt(i)) return false;
                }else wordChar.put(words[i],pattern.charAt(i));
                charWord.put(pattern.charAt(i),words[i]);
            }
        }
        return true;
    }
}