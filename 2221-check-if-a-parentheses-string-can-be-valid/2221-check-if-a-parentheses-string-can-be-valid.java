class Solution {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();
        if(n%2==1) return false;
        int open = 0;
        int unlockInds = 0;
        for(int i = 0; i<n; i++){
            if(locked.charAt(i) == '0') unlockInds++;
            else if(s.charAt(i) == '(') open++;
            else{
                if(open>0) open--;
                else if(unlockInds>0) unlockInds--;
                else return false;
            }
        }
        int balanceCheck = 0;
        for(int i = n-1; i>=0; i--){
            if(locked.charAt(i) == '0'){
                unlockInds--;
                balanceCheck--;
            } 
            else if(s.charAt(i) == '('){
                balanceCheck++;
                open--;
            }
            else if(s.charAt(i) == ')') balanceCheck--;
            if(balanceCheck>0) return false;
            if(open == 0 && unlockInds == 0) break;
        }
        if(open>0) return false;
        return true;
    }
}