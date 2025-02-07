class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        HashMap<Integer,Integer> mpp = new HashMap<>();
        HashMap<Integer,Integer> cols = new HashMap<>();
        int n = queries.length;
        int[] ans = new int[n];
        for(int i = 0; i<n; i++){
            int ball = queries[i][0];
            int color = queries[i][1];
            if(mpp.containsKey(ball)){
                int prevColor = mpp.get(ball);
                cols.put(prevColor,cols.get(prevColor)-1);
                if(cols.get(prevColor) == 0) cols.remove(prevColor);
            }
            mpp.put(ball,color);
            cols.put(color,cols.getOrDefault(color,0)+1);
            ans[i] = cols.size();
        }
        return ans;
    }
}