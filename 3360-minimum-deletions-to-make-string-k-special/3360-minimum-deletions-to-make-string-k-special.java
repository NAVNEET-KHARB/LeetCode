class Solution {
    public int minimumDeletions(String word, int k) {
        HashMap<Character,Integer> mpp = new HashMap<>();
        for(char c : word.toCharArray()){
            mpp.put(c,mpp.getOrDefault(c,0)+1);
        }
        int ans = word.length();
        for(int a : mpp.values()){
            int deleted = 0;
            for(int b : mpp.values()){
                if(a>b) deleted += b;
                else if(b>a+k) deleted += b-(a+k);
            }
            ans = Math.min(ans,deleted);
        }
        return ans;
    }
}