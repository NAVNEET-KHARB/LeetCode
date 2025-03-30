class Solution {
    public List<Integer> partitionLabels(String s) {
        int n = s.length();
        HashMap<Character,Integer> mpp = new HashMap<>();
        for(int i = 0; i<n; i++){
            char c = s.charAt(i);
            mpp.put(c,i);
        }
        int ind = 0, partStart = 0, partEnd = 0;
        List<Integer> ans = new ArrayList<>();
        while(ind<n){
            char c = s.charAt(ind);
            partEnd = Math.max(partEnd,mpp.get(c));
            if(ind == partEnd){
                ans.add(partEnd-partStart+1);
                partStart = ind+1;
            }
            ind++;
        }
        return ans;
    }
}