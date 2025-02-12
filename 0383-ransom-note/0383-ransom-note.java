class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character,Integer> ransom = new HashMap<>();
        HashMap<Character,Integer> mag = new HashMap<>();
        for(char c : ransomNote.toCharArray()){
            ransom.put(c,ransom.getOrDefault(c,0)+1);
        }
        for(char c : magazine.toCharArray()){
            mag.put(c,mag.getOrDefault(c,0)+1);
        }
        for(char it : ransom.keySet()){
            if(ransom.get(it)>mag.getOrDefault(it,0)) return false;
        }
        return true;
    }
}