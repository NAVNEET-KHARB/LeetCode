class Solution {
    public String removeKdigits(String num, int k) {
        int n = num.length();
        if(n == k) return "0";
        Stack<Integer> st = new Stack<>();
        for(char c : num.toCharArray()){
            while(!st.isEmpty() && k>0 && st.peek()>c-'0'){
                st.pop();
                k--;
            }
            st.push(c-'0');
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        String ans = "";
        while(!st.isEmpty()){
            ans = st.pop().toString() + ans;
        }
        int ind = 0, m = ans.length();
        while(ind<m){
            if(ans.charAt(ind) != '0') break;
            ind++;
        }
        return ind == m?"0":ans.substring(ind);
    }
}