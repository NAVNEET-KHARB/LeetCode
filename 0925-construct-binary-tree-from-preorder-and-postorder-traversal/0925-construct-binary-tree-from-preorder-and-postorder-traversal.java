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
    private int preIndex = 0;
    private int postIndex = 0;
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        return constructTree(preorder, postorder);
    }
    private TreeNode constructTree(int[] preorder, int[] postorder) {
        TreeNode root = new TreeNode(preorder[preIndex++]);
        if (root.val != postorder[postIndex]) {
            root.left = constructTree(preorder, postorder);
        }
        if (root.val != postorder[postIndex]) {
            root.right = constructTree(preorder, postorder);
        }
        postIndex++;
        return root;
    }
}