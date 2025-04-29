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
    public void solve(TreeNode root, long currSum, int targetSum, int[] ans, HashMap<Long,Integer> prefixSum){
        if(root == null) return;
        currSum += root.val;
        ans[0] += prefixSum.getOrDefault(currSum-targetSum,0);
        prefixSum.put(currSum,prefixSum.getOrDefault(currSum,0)+1);
        solve(root.left,currSum,targetSum,ans,prefixSum);
        solve(root.right,currSum,targetSum,ans,prefixSum);
        prefixSum.put(currSum,prefixSum.get(currSum)-1);
    }
    public int pathSum(TreeNode root, int targetSum) {
        HashMap<Long,Integer> prefixSum = new HashMap<>();
        prefixSum.put(0L, 1);
        int[] ans = new int[1];
        solve(root,0,targetSum,ans,prefixSum);
        return ans[0];
    }
}