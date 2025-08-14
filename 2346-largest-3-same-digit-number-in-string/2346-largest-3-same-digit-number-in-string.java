class Solution {
    public String largestGoodInteger(String num) {
        String ans = "";
        int n = num.length();
        for (int i = 0; i <= n - 3; i++) {
            char c1 = num.charAt(i);
            char c2 = num.charAt(i + 1);
            char c3 = num.charAt(i + 2);
            if (c1 == c2 && c2 == c3) {
                String candidate = num.substring(i, i + 3);
                if (ans.isEmpty() || candidate.compareTo(ans) > 0) {
                    ans = candidate;
                }
            }
        }
        return ans;
    }
}