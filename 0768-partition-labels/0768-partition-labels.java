class Solution {
    public List<Integer> partitionLabels(String s) {
        int n = s.length();
        int[] lastOcc = new int[26];
        for(int i = 0; i<n; i++){
            lastOcc[s.charAt(i)-'a'] = i;
        }
        int ind = 0, partStart = 0, partEnd = 0;
        List<Integer> ans = new ArrayList<>();
        while(ind<n){
            char c = s.charAt(ind);
            partEnd = Math.max(partEnd,lastOcc[c-'a']);
            if(ind == partEnd){
                ans.add(partEnd-partStart+1);
                partStart = ind+1;
            }
            ind++;
        }
        return ans;
    }
}