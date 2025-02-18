class Solution {
    private int func(int currInd, int currCnt, char[] pArr, StringBuilder ans){
        if(currInd != pArr.length){
            if(pArr[currInd] == 'I'){
                func(currInd+1,currInd+1,pArr,ans);
            }else currCnt = func(currInd+1,currCnt,pArr,ans);
        }
        ans.append(currCnt+1);
        return currCnt+1;
    }
    public String smallestNumber(String pattern) {
        StringBuilder ans = new StringBuilder();
        func(0,0,pattern.toCharArray(),ans);
        return ans.reverse().toString();
    }
}