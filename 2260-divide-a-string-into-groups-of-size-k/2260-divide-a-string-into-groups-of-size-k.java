class Solution {
    public String[] divideString(String s, int k, char fill) {
        int n = s.length();
        int parts = n/k + (n%k>0?1:0), part = 0;
        String[] ans = new String[parts];
        int curr = 0;
        while (curr < n) {
            int end = Math.min(curr + k, n);
            ans[part++] = s.substring(curr, end);
            curr += k;
        }
        String last = ans[parts-1];
        if (last.length() < k) {
            last += String.valueOf(fill).repeat(k - last.length());
            ans[parts-1] = last;
        }
        return ans;
    }
}