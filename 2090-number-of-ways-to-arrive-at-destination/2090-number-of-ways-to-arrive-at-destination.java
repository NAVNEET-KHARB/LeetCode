class Solution {
    class Pair<S,P>{
        private S first;
        private P second;
        Pair(S first, P second){
            this.first = first;
            this.second = second;
        }
        public S first(){
            return this.first;
        }
        public P second(){
            return this.second;
        }
        public void sSec(P second){
            this.second = second;
        }
    }
    public int countPaths(int n, int[][] roads) {
        ArrayList<ArrayList<Pair<Integer,Integer>>> adj = new ArrayList<>();
        for(int i = 0; i<n; i++) adj.add(new ArrayList<>());
        for(int[] road : roads){
            adj.get(road[0]).add(new Pair<>(road[1],road[2]));
            adj.get(road[1]).add(new Pair<>(road[0],road[2]));
        }
        PriorityQueue<Pair<Long,Integer>> pq = new PriorityQueue<>((a,b)->Long.compare(a.first(), b.first()));
        long[] dist = new long[n];
        for(int i = 0; i<n; i++) dist[i] = Long.MAX_VALUE;
        int[] ways = new int[n];
        dist[0] = 0;
        ways[0] = 1;
        int mod = (int) (1e9 + 7);
        pq.add(new Pair<>(dist[0],0));
        while(!pq.isEmpty()){
            Pair<Long,Integer> distP = pq.poll();
            long dis = distP.first();
            int node = distP.second();
            if(dis>dist[node]) continue;
            for(Pair<Integer,Integer> adjP : adj.get(node)){
                int adjNode = adjP.first();
                int roadW = adjP.second();
                long newDist = dis + roadW;
                if(newDist<dist[adjNode]){
                    dist[adjNode] = newDist;
                    pq.add(new Pair<>(dist[adjNode],adjNode));
                    ways[adjNode] = ways[node];
                }else if(newDist == dist[adjNode]){
                    ways[adjNode] = (ways[node]+ways[adjNode])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
}