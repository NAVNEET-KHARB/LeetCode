class Solution {
    public int largestAltitude(int[] gain) {
        int maxAlt = 0;
        int tempAlt = 0;
        for(int alt: gain){
            tempAlt += alt;
            maxAlt = Math.max(maxAlt,tempAlt);
        }
        return maxAlt;
    }
}