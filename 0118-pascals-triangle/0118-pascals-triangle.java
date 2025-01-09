class Solution {
    public List<Integer> generateRow(int row){
        List<Integer> ansRow = new ArrayList<>();
        long ans = 1;
        ansRow.add((int)ans);
        for(int col = 1; col<row; col++){
            ans *= (row-col);
            ans /= col;
            ansRow.add((int)ans);
        }
        return ansRow;
    }
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        for(int row = 1; row<=numRows; row++){
            ans.add(generateRow(row));
        }
        return ans;
    }
}