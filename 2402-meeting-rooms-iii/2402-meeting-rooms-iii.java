class Solution {
    public int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings, (a,b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });
        PriorityQueue<Integer> availableRooms = new PriorityQueue<>();
        for(int i = 0; i<n; i++) availableRooms.add(i);
        PriorityQueue<long[]> busyRooms = new PriorityQueue<>((a,b) ->{
            if(a[0] != b[0]) return Long.compare(a[0],b[0]);
            return Long.compare(a[1],b[1]);
        });
        
        int[] roomCnt = new int[n];
        for(int[] meeting : meetings){
            int start = meeting[0];
            int end = meeting[1];
            int duration = end-start;
            int room;
            while(!busyRooms.isEmpty() && busyRooms.peek()[0]<=start){
                availableRooms.add((int)busyRooms.poll()[1]);
            }
            if(!availableRooms.isEmpty()){
                room = (int)availableRooms.poll();
                busyRooms.add(new long[]{end,room});
            }else{
                long[] prevMeet = busyRooms.poll();
                room = (int)prevMeet[1];
                long newEnd = prevMeet[0] + duration;
                busyRooms.add(new long[]{newEnd,room});
            }
            roomCnt[room]++;
        }
        
        int maxCnt = roomCnt[0];
        int maxRoom = 0;
        for(int i = 1; i<n; i++){
            if(roomCnt[i]>maxCnt){
                maxCnt = roomCnt[i];
                maxRoom = i;
            }
        }
        return maxRoom;
    }
}