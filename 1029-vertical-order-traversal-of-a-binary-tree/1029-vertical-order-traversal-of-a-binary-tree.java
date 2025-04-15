/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> mpp = new TreeMap<>();
        Queue<Pair<TreeNode, int[]>> q = new LinkedList<>();
        q.add(new Pair<>(root, new int[] { 0, 0 }));
        while (!q.isEmpty()) {
            Pair<TreeNode, int[]> p = q.poll();
            TreeNode node = p.getKey();
            int vertical = p.getValue()[0];
            int level = p.getValue()[1];
            mpp.computeIfAbsent(vertical, k -> new TreeMap<>()).computeIfAbsent(level, k -> new PriorityQueue<>()).add(node.val);
            if (node.left != null)
                q.add(new Pair<>(node.left, new int[] { vertical - 1, level + 1 }));
            if (node.right != null)
                q.add(new Pair<>(node.right, new int[] { vertical + 1, level + 1 }));
        }
        for (TreeMap<Integer, PriorityQueue<Integer>> levels : mpp.values()) {
            List<Integer> col = new ArrayList<>();
            for (PriorityQueue<Integer> nodes : levels.values()) {
                while (!nodes.isEmpty()) {
                    col.add(nodes.poll());
                }
            }
            ans.add(col);
        }
        return ans;
    }

}