class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> ans = new ArrayList<>();
        int currNum = 1;
        for(int i = 0; i<n; i++){
            ans.add(currNum);
            if(currNum * 10 <= n){
                currNum *= 10;
            }else{
                while(currNum % 10 == 9 || currNum >= n) currNum /= 10;
                currNum++;
            }
        }
        return ans;
    }
}