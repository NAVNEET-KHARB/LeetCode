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
    public void preOrder(TreeNode root, int[] cnt, int k, int[] ans){
        if(root == null || cnt[0]>=k) return;
        preOrder(root.left,cnt,k,ans);
        cnt[0]++;
        if(cnt[0] == k){
            ans[0] = root.val;
            return;
        }
        preOrder(root.right,cnt,k,ans);
    }
    public int kthSmallest(TreeNode root, int k) {
        int[] ans = new int[1];
        int[] cnt = new int[1];
        preOrder(root,cnt,k,ans);
        return ans[0];
    }
}