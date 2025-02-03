class Solution {
    int maxInd(int[][]mat, int row, int col){
        int ans = 0;
        for(int i = 1; i<row; i++){
            if(mat[i][col]>mat[ans][col]) ans = i;
        }
        return ans;
    }
    public int[] findPeakGrid(int[][] mat) {
        int rows = mat.length, cols = mat[0].length;
        int low = 0, high = cols-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int row = maxInd(mat,rows,mid);
            int left = mid-1>=0?mat[row][mid-1]:-1;
            int right = mid+1<cols?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right) return new int[]{row,mid};
            else if(left>mat[row][mid]) high = mid-1;
            else low = mid+1;
        }
        return new int[]{-1,-1};
    }
}