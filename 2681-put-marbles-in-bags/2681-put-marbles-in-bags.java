class Solution {
    public long putMarbles(int[] weights, int k) {
        int n = weights.length;
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a,b)->b-a);
        for(int i = 0; i<n-1; i++){
            minHeap.add(weights[i] + weights[i+1]);
            maxHeap.add(weights[i] + weights[i+1]);
        }
        long maxScore = 0, minScore = 0;
        for(int i = 0; i<k-1; i++){
            minScore += minHeap.poll();
            maxScore += maxHeap.poll();
        }
        return maxScore-minScore;
    }
}