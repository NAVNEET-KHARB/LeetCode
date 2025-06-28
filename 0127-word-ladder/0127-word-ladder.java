class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        HashSet<String> set = new HashSet<>(wordList);
        if(!set.contains(endWord)) return 0;
        Queue<Pair<String,Integer>> q = new LinkedList<>();
        q.add(new Pair<>(beginWord, 1));
        if(set.contains(beginWord)) set.remove(beginWord);
        while(!q.isEmpty()){
            Pair<String,Integer> p = q.poll();
            String currWord = p.getKey();
            int steps = p.getValue();
            if(currWord.equals(endWord)) return steps;
            char[] cArr = currWord.toCharArray();
            for(int i = 0; i<cArr.length; i++){
                char og = cArr[i];
                for(char c = 'a'; c<='z'; c++){
                    cArr[i] = c;
                    String successor = new String(cArr);
                    if(set.contains(successor)){
                        q.add(new Pair<>(successor,steps+1));
                        set.remove(successor);
                    }
                }
                cArr[i] = og;
            }
        }
        return 0;
    }
}