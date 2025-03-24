class Solution {
    public int countDays(int days, int[][] meetings) {
        TreeMap<Integer,Integer> mpp = new TreeMap<>();
        int prefixSum = 0, freeDays = 0, prevDay = days;
        for(int[] meeting : meetings){
            prevDay = Math.min(prevDay,meeting[0]);
            mpp.put(meeting[0],mpp.getOrDefault(meeting[0],0)+1);
            mpp.put(meeting[1]+1,mpp.getOrDefault(meeting[1]+1,0)-1);
        }
        freeDays = prevDay-1;
        for(Map.Entry<Integer,Integer> meet : mpp.entrySet()){
            int currDay = meet.getKey();
            if(prefixSum == 0) freeDays += currDay-prevDay;
            prefixSum += meet.getValue();
            prevDay = currDay;
        }
        freeDays += days-prevDay+1;
        return freeDays;
    }
}