class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        Stack<Integer> st = new Stack<>();
        int ans = 0;
        for(int i = 0; i<n; i++){
            while(!st.isEmpty() && heights[st.peek()]>heights[i]){
                int currInd = st.pop(), prevInd = st.isEmpty()?-1:st.peek();
                ans = Math.max((i-prevInd-1)*heights[currInd],ans);
            }
            st.push(i);
        }
        while(!st.isEmpty()){
            int currInd = st.pop(), prevInd = st.isEmpty()?-1:st.peek();
            ans = Math.max((n-prevInd-1)*heights[currInd],ans);
        }
        return ans;
    }
    public int maximalRectangle(char[][] matrix) {
        int n = matrix.length, m = matrix[0].length, ans = 0;
        int[] heights = new int[m];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }
            ans = Math.max(ans,largestRectangleArea(heights));
        }
        return ans;
    }
}