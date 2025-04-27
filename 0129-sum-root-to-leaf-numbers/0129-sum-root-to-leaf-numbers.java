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
    public void preOrder(TreeNode root, int curr, int[] ans){
        if(root == null) return;
        curr = curr*10 + root.val;
        if(root.left == null && root.right == null){
            ans[0] += curr;
            return;
        }
        preOrder(root.left,curr,ans);
        preOrder(root.right,curr,ans);
    }
    public int sumNumbers(TreeNode root) {
        int[] ans = new int[1];
        int curr = 0;
        preOrder(root,curr,ans);
        return ans[0];
    }
}