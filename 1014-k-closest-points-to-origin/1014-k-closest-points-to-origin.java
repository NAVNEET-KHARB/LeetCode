class Solution {
    public class Pair<K, V> {
        private K key;
        private V value;
        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }
        public K getKey() {
            return key;
        }
        public V getValue() {
            return value;
        }
    }
    public double distance(int a, int b){
        return Math.sqrt((Math.pow(a,2)+Math.pow(b,2)));
    }
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Pair<Double,int[]>> pq = new PriorityQueue<>(Comparator.comparingDouble(Pair::getKey));
        for(int[] point : points){
            double dist = distance(point[0],point[1]);
            pq.add(new Pair(dist,point));
        }
        int[][] ans = new int[k][2];
        for(int i = 0; i<k; i++){
            ans[i] = pq.poll().getValue();
        }
        return ans;
    }
}