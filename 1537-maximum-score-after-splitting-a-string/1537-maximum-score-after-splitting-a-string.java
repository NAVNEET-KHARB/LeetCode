class Solution {
    public int maxScore(String s) {
        int ones = 0;
        int zeroes = 0;
        int ans = Integer.MIN_VALUE;
        for(int i = 0; i<s.length()-1; i++){
            if(s.charAt(i) == '1') ones++;
            else zeroes++;
            ans = Math.max(ans, zeroes-ones);
        }
        if(s.charAt(s.length()-1) == '1') ones++;
        return ans+ones;
    }
}