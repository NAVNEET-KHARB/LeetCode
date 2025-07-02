class Solution {
    private void dfs(String word, List<String> curr, HashMap<String,Integer> mpp, List<List<String>> ans){
        if(mpp.get(word) == 1){
            List<String> added = new ArrayList<>(curr);
            Collections.reverse(added);
            ans.add(added);
            return;
        }
        int steps = mpp.get(word);
        char[] cArr = word.toCharArray();
        for(int i = 0; i<cArr.length; i++){
            char og = cArr[i];
            for(char c = 'a'; c<='z'; c++){
                cArr[i] = c;
                String next = new String(cArr);
                if(mpp.containsKey(next) && mpp.get(next) == steps-1){
                    curr.add(next);
                    dfs(next,curr,mpp,ans);
                    curr.remove(curr.size()-1);
                }
            }
            cArr[i] = og;
        }
    }
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        HashSet<String> set = new HashSet<>(wordList);
        HashMap<String,Integer> mpp = new HashMap<>();
        List<List<String>> ans = new ArrayList<>();
        if(!set.contains(endWord)) return ans;
        Queue<String> q = new LinkedList<>();
        q.add(beginWord);
        if(set.contains(beginWord)) set.remove(beginWord);
        mpp.put(beginWord,1);
        while(!q.isEmpty()){
            String curr = q.poll();
            int steps = mpp.get(curr);
            if(endWord.equals(curr)) break;
            char[] cArr = curr.toCharArray();
            for(int i = 0; i<cArr.length; i++){
                char og = cArr[i];
                for(char c = 'a'; c<='z'; c++){
                    cArr[i] = c;
                    String next = new String(cArr);
                    if(set.contains(next)){
                        q.add(next);
                        mpp.put(next,steps+1);
                        set.remove(next);
                    }
                }
                cArr[i] = og;
            }
        }
        if(!mpp.containsKey(endWord)) return ans;
        List<String> ls = new ArrayList<>();
        ls.add(endWord);
        dfs(endWord,ls,mpp,ans);
        return ans;
    }
}