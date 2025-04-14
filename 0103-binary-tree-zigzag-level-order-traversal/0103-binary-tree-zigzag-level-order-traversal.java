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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        boolean dir = true;
        while(!q.isEmpty()){
            int n = q.size();
            List<Integer> level = new ArrayList<>(Collections.nCopies(n, 0));
            for(int i = 0; i<n; i++){
                TreeNode curr = q.poll();
                if(dir) level.set(i,curr.val);
                else level.set(n-1-i,curr.val);
                if(curr.left != null) q.add(curr.left);
                if(curr.right != null) q.add(curr.right);
            }
            ans.add(level);
            dir = !dir;
        }
        return ans;
    }
}