class Solution {
    public long coloredCells(int n) {
        long ans = 1;
        long toAdd = 4;
        n--;
        while(n>0){
            ans += toAdd;
            toAdd += 4;
            n--;
        }
        return ans;
    }
}