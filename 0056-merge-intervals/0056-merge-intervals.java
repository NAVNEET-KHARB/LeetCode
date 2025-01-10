class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return new int[0][0];
        }
        ArrayList<ArrayList<Integer>> ansArr = new ArrayList<>();
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        int[] prevInterval = new int[2];
        int eI = 0;
        for(int[]interval : intervals){
            if(ansArr.size() == 0 || interval[0]>prevInterval[1]){
                ArrayList<Integer> temp = new ArrayList<>(Arrays.asList(interval[0],interval[1]));
                ansArr.add(temp);
                prevInterval[0] = interval[0];
                prevInterval[1] = interval[1];
                eI++;
            }else{
                int el = Math.max(interval[1],prevInterval[1]);
                ansArr.get(eI-1).set(1,el);
                prevInterval[1] = el;
            }
        }
        int[][] ans = new int[ansArr.size()][2];
        for(int i = 0; i<ansArr.size(); i++){
            ans[i][0] = ansArr.get(i).get(0);
            ans[i][1] = ansArr.get(i).get(1);
        }
        return ans;
    }
}