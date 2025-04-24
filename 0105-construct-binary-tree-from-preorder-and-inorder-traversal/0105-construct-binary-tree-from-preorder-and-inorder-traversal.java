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
    private TreeNode buildTree(int[] preOrder, int preStart, int preEnd, int[] inOrder, int inStart, int inEnd, HashMap<Integer,Integer> inMap){
        if(preStart > preEnd || inStart > inEnd) return null;
        TreeNode root = new TreeNode(preOrder[preStart]);
        int inInd = inMap.get(root.val);
        int leftNums = inInd-inStart;
        root.left = buildTree(preOrder,preStart+1,preStart+leftNums,inOrder,inStart,inInd-1,inMap);
        root.right = buildTree(preOrder,preStart+leftNums+1,preEnd,inOrder,inInd+1,inEnd,inMap);
        return root;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        HashMap<Integer,Integer> inMap = new HashMap<>();
        int n = inorder.length;
        for(int i = 0; i<n; i++) inMap.put(inorder[i],i);
        TreeNode root = buildTree(preorder,0,n-1,inorder,0,n-1,inMap);
        return root;
    }
}