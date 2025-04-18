class Solution {
    public String countAndSay(int n) {
        StringBuilder st = new StringBuilder("1");
        n--;
        while(n>0){
            StringBuilder temp = new StringBuilder();
            int cnt = 1;
            char prev = st.charAt(0);
            for(int i = 1; i<st.length(); i++){
                if(st.charAt(i) == prev) cnt++;
                else{
                    temp.append(cnt).append(prev);
                    prev = st.charAt(i);
                    cnt = 1;
                }
            }
            temp.append(cnt).append(prev);
            st = temp;
            n--;
        }
        return st.toString();
    }
}