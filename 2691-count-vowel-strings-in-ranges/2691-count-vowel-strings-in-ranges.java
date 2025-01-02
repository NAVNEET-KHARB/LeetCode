class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        HashMap<Integer,Integer> mpp = new HashMap<>();
        HashSet<Character> vowels = new HashSet<>(
            Arrays.asList('a', 'e', 'i', 'o', 'u')
        );
        int index = 0;
        int cnt = 0;
        mpp.put(-1,0);
        for(String str : words){
            if(vowels.contains(str.charAt(0)) && vowels.contains(str.charAt(str.length()-1))) cnt++;
            mpp.put(index,cnt);
            index++;
        }
        int[] ans = new int[queries.length];
        index = 0;
        for(int[] query : queries){
            ans[index] = (mpp.get(query[1])-mpp.get(query[0]-1));
            index++;
        }
        return ans;
    }
}