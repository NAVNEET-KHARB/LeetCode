class Solution {
    public int findLucky(int[] arr) {
        int[] num = new int[501];
        int ans = -1;
        for(int a : arr) num[a]++;
        for(int i = 1; i<=500; i++) if(num[i] == i) ans = Math.max(ans,i);
        return ans;
    }
}