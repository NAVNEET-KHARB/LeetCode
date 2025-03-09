class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length;
        int cnt = 1, ans = 0, lastCol = colors[0];
        for(int i = 1; i<n+k-1; i++){
            int ind = i%n;
            if(colors[ind] == lastCol) cnt = 1;
            else cnt++;
            if(cnt>=k) ans++;
            lastCol = colors[ind];
        }
        return ans;
    }
}