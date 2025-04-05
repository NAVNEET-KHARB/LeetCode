class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length, m = potions.length;
        Arrays.sort(potions);
        int[] pairs = new int[n];
        for(int i = 0; i<n; i++){
            int low = 0, high = m-1;
            while(low<=high){
                int mid = low+(high-low)/2;
                long num = (long)spells[i]*potions[mid];
                if(num>=success) high = mid-1;
                else low = mid+1;
            }
            pairs[i] = m - (high+1);
        }
        return pairs;
    }
}