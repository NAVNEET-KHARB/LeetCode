class Solution {
    public String sortSentence(String s) {
        String[] str = s.split(" ");
        String[] res = new String[str.length];
        StringBuilder sb = new StringBuilder();
        int i = 0;
        for (String elem : str) {
            i = (int) (elem.charAt(elem.length() - 1) - '0');
            res[i - 1] = elem.substring(0, elem.length() - 1);
        }
        int n = res.length;
        for (i = 0; i < n; i++){
            if(i!=n-1) sb.append(res[i]).append(" ");
            else sb.append(res[i]);
        }
        return sb.toString();
    }
}