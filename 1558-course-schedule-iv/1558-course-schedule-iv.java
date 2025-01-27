class Solution {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        boolean[][] reachable = new boolean[numCourses][numCourses];
        for (int[] prerequisite : prerequisites) {
            reachable[prerequisite[0]][prerequisite[1]] = true;
        }
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    if (reachable[i][k] && reachable[k][j]) {
                        reachable[i][j] = true;
                    }
                }
            }
        }
        List<Boolean> ans = new ArrayList<>();
        for (int[] query : queries) {
            ans.add(reachable[query[0]][query[1]]);
        }
        return ans;
    }
}