public class Solution {
    public int minimizeXor(int num1, int num2) {
        int ans = 0;
        int tar = Integer.bitCount(num2);
        int setCnt = 0;
        int curr = 31;
        while (setCnt < tar) {
            if (isSet(num1, curr) ||(tar - setCnt > curr) ) {
                ans = setBit(ans, curr);
                setCnt++;
            }
            curr--;
        }
        return ans;
    }
    private boolean isSet(int x, int bit) {
        return (x & (1 << bit)) != 0;
    }
    private int setBit(int x, int bit) {
        return x | (1 << bit);
    }
}