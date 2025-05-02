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
    private void inOrder(TreeNode root, int k, int[] cnt, int[] ans){
        if(root == null || cnt[0]>=k) return;
        inOrder(root.left,k,cnt,ans);
        cnt[0]++;
        if(cnt[0] == k){
            ans[0] = root.val;
            return;
        }
        inOrder(root.right,k,cnt,ans);
    }
    public int kthSmallest(TreeNode root, int k) {
        int[] cnt = new int[1];
        int[] ans = new int[1];
        inOrder(root,k,cnt,ans);
        return ans[0];
    }
}