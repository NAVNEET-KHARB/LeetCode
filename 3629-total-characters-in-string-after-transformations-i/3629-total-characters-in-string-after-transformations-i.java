class Solution {
    public int lengthAfterTransformations(String s, int t) {
        final int MOD = 1000000007;
        long[] freq = new long[26];
        for(char c : s.toCharArray()) freq[c-'a']++;
        while(t>0){
            long[] tempFreq = new long[26];
            for(int i = 0; i<26; i++){
                if(freq[i]>0){
                    if(i == 25){
                        tempFreq[0] = (freq[i] + tempFreq[0])%MOD;
                        tempFreq[1] = (freq[i] + tempFreq[1])%MOD;
                    }else tempFreq[i+1] = (freq[i] + tempFreq[i+1])%MOD;
                }
            }
            freq = tempFreq;
            t--;
        }
        int ans = 0;
        for(long val : freq) ans = (ans + (int)val)%MOD;
        return ans;
    }
}