class Solution {
    public int equalPairs(int[][] grid) {
        int ans = 0;
        int row = 0;
        while(row<grid.length){
            HashMap<Integer,Integer> mpp = new HashMap<>();
            for(int j = 0; j<grid.length; j++) mpp.put(j,grid[row][j]);
            for(int col = 0; col<grid.length; col++){
                boolean equal = true;
                for(int r = 0; r<grid.length; r++){
                    if(grid[r][col] == mpp.get(r)) continue;
                    else{
                        equal = false;
                        break;
                    }
                }
                if(equal) ans++;
            }
            row++;
        }
        return ans;
    }
}