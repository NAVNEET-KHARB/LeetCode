class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer,Integer> hash = new HashMap<>();
        for(int num : arr) hash.put(num,hash.getOrDefault(num,0)+1);
        Set<Integer> s = new HashSet<>();
        for (int x : hash.values()) s.add(x);
        return hash.size() == s.size();
    }
}