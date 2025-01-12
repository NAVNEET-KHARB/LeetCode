class Solution {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();
        if(n%2==1) return false;
        Stack<Integer> open = new Stack<>();
        Stack<Integer> unlockInds = new Stack<>();
        for(int i = 0; i<n; i++){
            if(locked.charAt(i) == '0') unlockInds.push(i);
            else if(s.charAt(i) == '(') open.push(i);
            else{
                if(!open.empty()) open.pop();
                else if(!unlockInds.empty()) unlockInds.pop();
                else return false;
            }
        }
        while(!open.empty() && !unlockInds.empty() && open.peek()<unlockInds.peek()){
            open.pop();
            unlockInds.pop();
        }
        if(!open.empty()) return false;
        return true;
    }
}