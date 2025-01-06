class Solution {
    public String sortSentence(String s) {
        HashMap<Integer,String> mpp = new HashMap<>();
        String temp = "";
        int highInd = -1;
        for(int i = 0; i<s.length(); i++){
            if(s.charAt(i) == ' ') continue;
            else if(Character.isDigit(s.charAt(i)) == true){
                mpp.put(s.charAt(i)-'0',temp);
                temp = "";
                highInd = Math.max(highInd,(s.charAt(i)-'0'));
            }
            else temp += s.charAt(i);
        }
        temp = "";
        for(int i = 0; i<highInd; i++){
            temp += mpp.get(i+1);
            if(i!=highInd-1) temp += ' ';
        }
        return temp;
    }
}