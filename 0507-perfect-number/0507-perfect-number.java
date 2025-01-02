class Solution {
    public boolean checkPerfectNumber(int num) {
        if(num == 1) return false;
        int numCheck = 1;
        for(int i = 2; i*i<=num; i++){
            if(num%i == 0){
                numCheck += i;
                if((num/i) != i) numCheck += (num/i);
            }
        }
        return (num == numCheck);
    }
}