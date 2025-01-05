class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] shiftArr = new int[n];
        for(int[] query : shifts){
            if(query[2] == 1){
                shiftArr[query[0]]++;
                if(query[1]+1<n){
                    shiftArr[query[1]+1]--;
                }
            }else{
                shiftArr[query[0]]--;
                if(query[1]+1<n){
                    shiftArr[query[1]+1]++;
                }
            }
        }
        StringBuilder str = new StringBuilder(s);
        int totShifts = 0;
        for(int i = 0; i<n; i++){
            totShifts = (totShifts+shiftArr[i])%26;
            if(totShifts<0) totShifts += 26;
            int charShift = ((s.charAt(i)-'a')+ totShifts)%26;
            char newChar = (char)('a' + charShift);
            str.setCharAt(i,newChar);
        }
        return str.toString();
    }
}