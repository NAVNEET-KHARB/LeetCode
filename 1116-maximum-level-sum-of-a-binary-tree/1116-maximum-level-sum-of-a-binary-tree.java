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
    public int maxLevelSum(TreeNode root) {
        if(root.left == null && root.right == null) return 1;
        int maxSum = Integer.MIN_VALUE, ans = 0, level = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            level++;
            int sz = q.size(), curr = 0;
            for(int i = 0; i<sz; i++){
                TreeNode node = q.poll();
                curr += node.val;
                if(node.left != null) q.add(node.left);
                if(node.right != null) q.add(node.right);
            }
            if(maxSum<curr){
                maxSum = curr;
                ans = level;
            }
        }
        return ans;
    }
}