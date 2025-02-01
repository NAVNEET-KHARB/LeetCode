class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int s = flowerbed.length;
        int planted = 0;
        for(int i = 0; i<s; i++){
            if(flowerbed[i] == 0){
                boolean left = (i==0)||(flowerbed[i-1]==0);
                boolean right = (i==s-1)||(flowerbed[i+1]==0);
                if(left && right){
                    planted++;
                    flowerbed[i] = 1;
                    if(planted>=n) return true;
                }
            }
        }
        if(planted>=n) return true;
        return false;
    }
}