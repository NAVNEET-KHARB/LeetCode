class Solution {
    public int maxDistance(String s, int k) {
        int n = s.length();
        int lati = 0, longi = 0, ans = 0;
        for(int i = 0; i<n; i++){
            char dir = s.charAt(i);
            switch(dir){
                case 'N':
                    lati++;
                    break;
                case 'S':
                    lati--;
                    break;
                case 'E':
                    longi++;
                    break;
                case 'W':
                    longi--;
                    break;
            }
            ans = Math.max(ans, Math.min(Math.abs(lati)+Math.abs(longi)+k*2, i+1));
        }
        return ans;
    }
}