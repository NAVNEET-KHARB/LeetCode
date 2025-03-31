class Solution {
    public long putMarbles(int[] weights, int k) {
        int n = weights.length;
        int[] splits = new int[n-1];
        for(int i = 0; i<n-1; i++){
            splits[i] = weights[i] + weights[i+1];
        }
        Arrays.sort(splits);
        long maxScore = 0, minScore = 0;
        for(int i = 0; i<k-1; i++){
            minScore += splits[i];
            maxScore += splits[n-2-i];
        }
        return maxScore-minScore;
    }
}