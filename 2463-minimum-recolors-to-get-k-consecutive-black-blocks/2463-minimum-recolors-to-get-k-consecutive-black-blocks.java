class Solution {
    public int minimumRecolors(String blocks, int k) {
        int minReq = Integer.MAX_VALUE;
        int left = 0, right = 0, currW = 0;
        int n = blocks.length();
        while(right<n){
            if(blocks.charAt(right) == 'W') currW++;
            right++;
            if(right-left == k){
                minReq = Math.min(minReq,currW);
                if(blocks.charAt(left) == 'W') currW--;
                left++;
            }
        }
        return minReq;
    }
}