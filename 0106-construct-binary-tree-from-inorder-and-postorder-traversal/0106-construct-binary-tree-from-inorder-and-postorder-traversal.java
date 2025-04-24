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
    private TreeNode buildTree(int[] postOrder, int postStart, int postEnd, int[] inOrder, int inStart, int inEnd, HashMap<Integer,Integer> inMap){
        if(postStart > postEnd || inStart > inEnd) return null;
        TreeNode root = new TreeNode(postOrder[postEnd]);
        int inInd = inMap.get(root.val);
        int leftNums = inInd-inStart;
        root.left = buildTree(postOrder,postStart,postStart+leftNums-1,inOrder,inStart,inInd-1,inMap);
        root.right = buildTree(postOrder,postStart+leftNums,postEnd-1,inOrder,inInd+1,inEnd,inMap);
        return root;
    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        HashMap<Integer,Integer> inMap = new HashMap<>();
        int n = inorder.length;
        for(int i = 0; i<n; i++) inMap.put(inorder[i],i);
        TreeNode root = buildTree(postorder,0,n-1,inorder,0,n-1,inMap);
        return root;
    }
}