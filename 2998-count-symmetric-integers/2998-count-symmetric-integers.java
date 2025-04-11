class Solution {
    public boolean isSymmetric(int num){
        StringBuilder temp = new StringBuilder();
        temp.append(num);
        if(temp.length()%2==1) return false;
        int i = 0, j = temp.length()-1;
        int front = 0, last = 0;
        while(i<j){
            front += temp.charAt(i++)-'0';
            last += temp.charAt(j--)-'0';
        }
        return front == last;
    }
    public int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        while(low<=high){
            if(isSymmetric(low)){
                // System.out.println(low);
                ans++;
            }
            low++;
        }
        return ans;
    }
}