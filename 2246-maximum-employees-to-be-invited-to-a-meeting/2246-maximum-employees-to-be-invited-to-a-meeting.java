class Solution {
    public int maximumInvitations(int[] favorite) {
        int n = favorite.length;
        int[] inDegree = new int[n];
        for (int person = 0; person < n; ++person) {
            inDegree[favorite[person]]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int person = 0; person < n; ++person) {
            if (inDegree[person] == 0) {
                q.offer(person);
            }
        }
        int[] depth = new int[n];
        Arrays.fill(depth, 1);
        while (!q.isEmpty()) {
            int currentNode = q.poll();
            int nextNode = favorite[currentNode];
            depth[nextNode] = Math.max(depth[nextNode], depth[currentNode] + 1);
            if (--inDegree[nextNode] == 0) {
                q.offer(nextNode);
            }
        }
        int longestCycle = 0;
        int twoCycleInvitations = 0;
        for (int person = 0; person < n; ++person) {
            if (inDegree[person] == 0) continue;
            int cycleLength = 0;
            int current = person;
            while (inDegree[current] != 0) {
                inDegree[current] = 0; 
                cycleLength++;
                current = favorite[current];
            }
            if (cycleLength == 2) {
                twoCycleInvitations += depth[person] + depth[favorite[person]];
            } else {
                longestCycle = Math.max(longestCycle, cycleLength);
            }
        }

        return Math.max(longestCycle, twoCycleInvitations);
    }
}