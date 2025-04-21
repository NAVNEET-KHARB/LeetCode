class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        int x = 0, y = 0, curr = 0;
        for(int diff : differences){
            curr += diff;
            x = Math.min(curr,x);
            y = Math.max(curr,y);
            if(y-x > upper-lower) return 0;
        }
        return (upper-lower)-(y-x)+1;
    }
}