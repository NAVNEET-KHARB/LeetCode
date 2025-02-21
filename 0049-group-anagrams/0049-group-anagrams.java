class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>> mpp = new HashMap<>();
        for(String s : strs){
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);
            if(!mpp.containsKey(key)) mpp.put(key,new ArrayList<>());
            mpp.get(key).add(s);
        }
        return new ArrayList<>(mpp.values());
    }
}