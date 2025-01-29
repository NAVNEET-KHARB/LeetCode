class Solution {
    public int compress(char[] chars) {
        int n = chars.length;
        if(n<2) return n;
        String ans = "";
        char prev = chars[0];
        int cnt = 1;
        for(int i = 1; i<n; i++){
            if(chars[i] == prev) cnt++;
            else{
                ans += prev;
                prev = chars[i];
                if(cnt>1) ans += Integer.toString(cnt);
                cnt = 1;
            }
        }
        ans += prev;
        if(cnt>1) ans += Integer.toString(cnt);
        System.out.println(ans);
        for(int i = 0; i<ans.length(); i++){
            chars[i] = ans.charAt(i);
        }
        return ans.length();
    }
}