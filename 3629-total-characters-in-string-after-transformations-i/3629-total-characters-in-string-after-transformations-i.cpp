class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9+7;
        vector<long long> freq(26,0);
        for(char c: s) freq[c-'a']++;
        while(t){
            vector<long long> tempfreq(26,0);
            for(int i = 0; i<26; i++){
                if(freq[i]){
                    if(i== 25){
                        tempfreq[0] = (tempfreq[0] + freq[i])%MOD;
                        tempfreq[1] = (tempfreq[1] + freq[i])%MOD;
                    }
                    else tempfreq[i+1] = (tempfreq[i+1] + freq[i])%MOD;
                }
            }
            freq = tempfreq;
            t--;
        }
        int ans = 0;
        for(int val : freq) ans = (ans+val)%MOD;
        return ans;
    }
};