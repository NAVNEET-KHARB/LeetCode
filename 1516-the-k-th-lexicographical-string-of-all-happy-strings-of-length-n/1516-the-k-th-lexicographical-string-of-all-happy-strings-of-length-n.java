class Solution {
    public String getHappyString(int n, int k) {
        Stack<String> st = new Stack<>();
        int ind = 0;
        st.push("");
        while(!st.isEmpty()){
            String curr = st.pop();
            if(curr.length() == n){
                ind++;
                if(ind == k) return curr;
                continue;
            }
            for(char c = 'c'; c>='a'; c--){
                if(curr.length() == 0 || curr.charAt(curr.length()-1) != c) st.push(curr+c);
            }
        }
        return "";
    }
}