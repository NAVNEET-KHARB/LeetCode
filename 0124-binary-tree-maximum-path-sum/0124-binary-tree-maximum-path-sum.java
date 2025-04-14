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
    public int maxSum(TreeNode root, int[] pathSum){
        if(root == null) return 0;
        int lSum = Math.max(0,maxSum(root.left,pathSum));
        int rSum = Math.max(0,maxSum(root.right,pathSum));
        pathSum[0] = Math.max(pathSum[0],lSum+rSum+root.val);
        return root.val+Math.max(lSum,rSum);
    }
    public int maxPathSum(TreeNode root) {
        int[] pathSum = new int[1];
        pathSum[0] = Integer.MIN_VALUE;
        maxSum(root,pathSum);
        return pathSum[0];
    }
}