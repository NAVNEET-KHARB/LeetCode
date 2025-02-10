class Solution {
    public String clearDigits(String s) {
        StringBuilder st = new StringBuilder();
        for(char c : s.toCharArray()){
            if(Character.isDigit(c)){
                if(st.length()>0) st.deleteCharAt(st.length()-1);
            }
            else st.append(c);
        }
        return st.toString();
    }
}