class Solution {
    public String removeStars(String s) {
        char[] ans=s.toCharArray();
        int l=0;
        for(int i=0;i<ans.length;i++){
            if(ans[i]=='*'){
                l--;
            }
            else{
                ans[l++]=ans[i];
            }
        }
        return new String(ans,0,l);
    }
}