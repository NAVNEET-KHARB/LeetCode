class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        HashSet<Character> vowels = new HashSet<>(
            Arrays.asList('a', 'e', 'i', 'o', 'u')
        );
        int[] prefixSum = new int[words.length];
        int index = 0;
        int cnt = 0;
        for(String str : words){
            if(vowels.contains(str.charAt(0)) && vowels.contains(str.charAt(str.length()-1))) cnt++;
            prefixSum[index] = cnt;
            index++;
        }
        int[] ans = new int[queries.length];
        index = 0;
        for(int[] query : queries){
            ans[index] = (prefixSum[query[1]]-(query[0]==0?0:prefixSum[query[0]-1]));
            index++;
        }
        return ans;
    }
}