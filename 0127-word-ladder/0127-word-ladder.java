class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        HashSet<String> set = new HashSet<>(wordList);
        if(!set.contains(endWord)) return 0;
        Queue<Pair<String,Integer>> q = new LinkedList<>();
        q.add(new Pair<>(beginWord,1));
        set.remove(beginWord);
        while(!q.isEmpty()){
            Pair<String, Integer> p = q.poll();
            String word = p.getKey();
            int steps = p.getValue();
            if (word.equals(endWord)) return steps;
            char[] arr = word.toCharArray();
            for (int i = 0; i < arr.length; i++) {
                char original = arr[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    arr[i] = c;
                    String nextWord = new String(arr);
                    if (set.contains(nextWord)) {
                        q.add(new Pair<>(nextWord, steps + 1));
                        set.remove(nextWord);
                    }
                }
                arr[i] = original;
            }
        }
        return 0;
    }
}