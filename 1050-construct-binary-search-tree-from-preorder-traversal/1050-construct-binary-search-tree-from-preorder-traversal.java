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
    public TreeNode buildTree(int[] preorder, int[] ind, int maxRange){
        if(ind[0]>=preorder.length || preorder[ind[0]]>=maxRange) return null;
        TreeNode root = new TreeNode(preorder[ind[0]++]);
        root.left = buildTree(preorder,ind,root.val);
        root.right = buildTree(preorder,ind,maxRange);
        return root;
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        int[] ind = new int[1];
        return buildTree(preorder,ind,Integer.MAX_VALUE);
    }
}