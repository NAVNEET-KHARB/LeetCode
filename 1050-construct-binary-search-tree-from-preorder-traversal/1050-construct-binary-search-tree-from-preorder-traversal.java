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
    public TreeNode buildTree(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd, HashMap<Integer,Integer> inMap){
        if(preStart>preEnd || inStart>inEnd) return null;
        TreeNode root = new TreeNode(preorder[preStart]);
        int inInd = inMap.get(root.val);
        int leftNodes = inInd - inStart;
        root.left = buildTree(preorder, preStart+1, preStart+leftNodes, inorder, inStart, inInd-1, inMap);
        root.right = buildTree(preorder, preStart+leftNodes+1, preEnd, inorder, inInd+1, inEnd, inMap);
        return root;
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        int n = preorder.length;
        int[] inorder = new int[n];
        for(int i = 0; i<n; i++) inorder[i] = preorder[i];
        Arrays.sort(inorder);
        HashMap<Integer,Integer> inMap = new HashMap<>();
        for(int i = 0; i<n; i++) inMap.put(inorder[i],i);
        TreeNode root = buildTree(preorder, 0, n-1, inorder, 0, n-1, inMap);
        return root;
    }
}