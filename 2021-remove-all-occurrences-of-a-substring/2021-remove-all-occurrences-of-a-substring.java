class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder st = new StringBuilder(s);
        while (true) {
            int index = st.indexOf(part);
            if (index == -1) break;
            st.delete(index, index + part.length());
        }
        return st.toString();
    }
}