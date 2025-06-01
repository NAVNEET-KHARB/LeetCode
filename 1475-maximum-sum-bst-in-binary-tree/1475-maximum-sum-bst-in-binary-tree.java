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
    class Structure{
        int maxNode, minNode, sum;
        Structure(){}
        Structure(int maxNode, int minNode, int sum){
            this.maxNode = maxNode;
            this.minNode = minNode;
            this.sum = sum;
        }
    }
    public Structure helper(TreeNode root, int[] maxSum){
        if(root == null) return new Structure(Integer.MIN_VALUE,Integer.MAX_VALUE,0);
        Structure left = helper(root.left, maxSum);
        Structure right = helper(root.right, maxSum);
        Structure rootInfo;
        if(left.maxNode<root.val && root.val<right.minNode){
            rootInfo = new Structure(Math.max(root.val,right.maxNode), Math.min(root.val,left.minNode), left.sum+right.sum+root.val);
        }
        else rootInfo = new Structure(Integer.MAX_VALUE, Integer.MIN_VALUE, Math.max(left.sum, right.sum));
        maxSum[0] = Math.max(maxSum[0],rootInfo.sum);
        return rootInfo;
    }
    public int maxSumBST(TreeNode root) {
        int[] maxSum = new int[1];
        helper(root,maxSum);
        return maxSum[0];
    }
}