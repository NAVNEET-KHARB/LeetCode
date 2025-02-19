class Solution {
    void func(int n, int k, StringBuilder curr, String[] ans, int[] ind){
        if(curr.length() == n){
            ind[0]++;
            if(ind[0] == k) ans[0] = curr.toString();
            return;
        }
        for(char c = 'a'; c<='c'; c++){
            if(curr.length()>0 && curr.charAt(curr.length()-1) == c) continue;
            curr.append(c);
            func(n,k,curr,ans,ind);
            if(ans[0]!=null) return;
            curr.deleteCharAt(curr.length()-1);
        }
    }
    public String getHappyString(int n, int k) {
        StringBuilder curr = new StringBuilder();
        String[] ans = new String[1];
        int[] ind = new int[1];
        func(n,k,curr,ans,ind);
        return (ans[0] == null? "":ans[0]);
    }
}