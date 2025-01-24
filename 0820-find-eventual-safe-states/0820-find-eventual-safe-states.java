class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int V = graph.length;
        List<List<Integer>> adjR = new ArrayList<>();
        int[] inDegree = new int[V];
        List<Integer> safeStates = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i<V; i++) adjR.add(new ArrayList<>());
        for(int i = 0; i<V; i++){
            for(int neigh : graph[i]){
                adjR.get(neigh).add(i);
                inDegree[i]++;
            }
        }
        for(int i = 0; i<V; i++) if(inDegree[i] == 0) q.add(i);
        while(!q.isEmpty()){
            int node = q.poll();
            safeStates.add(node);
            for(int it : adjR.get(node)){
                inDegree[it]--;
                if(inDegree[it] == 0) q.add(it);
            }
        }
        Collections.sort(safeStates);
        return safeStates;
    }
}