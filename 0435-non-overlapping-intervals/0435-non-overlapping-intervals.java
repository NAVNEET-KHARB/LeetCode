class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals,(a,b)->a[1]-b[1]);
        int ans = 0;
        int n = intervals.length, i = 1;
        int last = intervals[0][1];
        while(i<n){
            if(last>intervals[i][0]) ans++;
            else last = intervals[i][1];
            i++;
        }
        return ans;
    }
}