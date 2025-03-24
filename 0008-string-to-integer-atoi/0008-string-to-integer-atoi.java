class Solution {
    public void solve(int[] ind, long[] ans, String s, boolean neg){
        if(ind[0] >= s.length() || !Character.isDigit(s.charAt(ind[0]))) return;
        ans[0] = ans[0] * 10 + (s.charAt(ind[0]) - '0');
        if (!neg && ans[0] > Integer.MAX_VALUE) {
            ans[0] = Integer.MAX_VALUE;
            return;
        }
        if (neg && -ans[0] < Integer.MIN_VALUE) {
            ans[0] = (long)Integer.MIN_VALUE * -1;
            return;
        }
        ind[0]++;
        solve(ind, ans, s, neg);
    }

    public int myAtoi(String s) {
        int[] ind = new int[1];
        long[] ans = new long[1];
        boolean neg = false;
        while (ind[0] < s.length() && s.charAt(ind[0]) == ' ') ind[0]++;
        if (ind[0] < s.length() && (s.charAt(ind[0]) == '-' || s.charAt(ind[0]) == '+')) {
            neg = (s.charAt(ind[0]) == '-');
            ind[0]++;
        }
        solve(ind, ans, s, neg);
        return neg ? (int) -ans[0] : (int) ans[0];
    }
}
