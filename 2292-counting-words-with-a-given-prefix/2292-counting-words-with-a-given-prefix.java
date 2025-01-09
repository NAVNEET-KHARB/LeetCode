class Solution {
    public int prefixCount(String[] words, String pref) {
        int ans = 0;
        int n = pref.length();
        for(String word : words){
            boolean flag = true;
            if(word.length()>=n){
                for(int i = 0; i<n; i++){
                    if(word.charAt(i)!=pref.charAt(i)){
                        flag = false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
}