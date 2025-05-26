class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        int n = colors.length();
        char[] c = colors.toCharArray();
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        int[] degree = new int[n];
        for (int[] edge : edges) {
            graph.putIfAbsent(edge[0], new HashSet<>());
            graph.get(edge[0]).add(edge[1]);
            degree[edge[1]]++;
        }
        int[][] map = new int[n][26];
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                queue.offer(i);
                map[i][c[i]-'a'] = 1;
            }
        }
        int seen = 0;
        int res = 0;
        while (!queue.isEmpty()) {
            int node = queue.poll();
            seen++;
            int max = getMax(map[node]);
            res = Math.max(res, max);
            Set<Integer> nexts = graph.getOrDefault(node, new HashSet<>());
            for (int next : nexts) {
                for (int i = 0; i < 26; i++) {
                    map[next][i] = Math.max(map[next][i], map[node][i] + (c[next]-'a' == i ? 1 : 0));
                }
                degree[next]--;
                if (degree[next] == 0) {
                    queue.offer(next);
                }
            }
        }
        
        return seen == n ? res : -1;
    }
    private int getMax(int[] nums) {
        int max = nums[0];
        for (int n : nums) {
            max = Math.max(max, n);
        }
        return max;
    }
}