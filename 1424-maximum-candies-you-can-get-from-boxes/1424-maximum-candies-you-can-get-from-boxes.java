class Solution {
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        int n = status.length;
        int totalCandies = 0;
        int[] vis = new int[n];
        int[] hasBox = new int[n];
        Queue<Integer> q = new LinkedList<>();
        for(int box : initialBoxes){
            hasBox[box] = 1;
            if(status[box] == 1){
                q.add(box);
                vis[box] = 1;
                totalCandies += candies[box];
            }
        }
        while(!q.isEmpty()){
            int currBox = q.poll();
            for(int key : keys[currBox]){
                status[key] = 1;
                if(vis[key] == 0 && hasBox[key] == 1){
                    q.add(key);
                    vis[key] = 1;
                    totalCandies += candies[key];
                }
            }
            for(int box : containedBoxes[currBox]){
                hasBox[box] = 1;
                if(vis[box] == 0 && status[box] == 1){
                    q.add(box);
                    vis[box] = 1;
                    totalCandies += candies[box];
                }
            }
        }
        return totalCandies;
    }
}