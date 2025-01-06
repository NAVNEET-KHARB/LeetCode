class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] ans = new int[n];
        int bl = 0, br = 0;
        int ml = 0, mr = 0;
        for(int i = 0; i<n; i++){
            ans[i] += ml;
            bl += (boxes.charAt(i) - '0');
            ml += bl;
            int j = n-1-i;
            ans[j] += mr;
            br += (boxes.charAt(j) - '0');
            mr += br;
        }
        return ans;
    }
}