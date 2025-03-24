class Solution {
    public int countDays(int days, int[][] meetings) {
        int freeDays = 0, lastWorkDay = 0;
        Arrays.sort(meetings,Comparator.comparingInt(a->a[0]));
        for(int[] meeting : meetings){
            int start = meeting[0], end = meeting[1];
            if(start>lastWorkDay+1) freeDays += start-lastWorkDay-1;
            lastWorkDay = Math.max(lastWorkDay,end);
        }
        freeDays += days-lastWorkDay;
        return freeDays;
    }
}