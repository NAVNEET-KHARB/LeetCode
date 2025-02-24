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
    public void func(TreeNode root, int sum, int targetSum, List<Integer> curr, List<List<Integer>> ans){
        if(root == null) return;
        sum += root.val;
        curr.add(root.val);
        if(root.left == null && root.right == null && sum == targetSum) {
            ans.add(new ArrayList<>(curr));
            curr.remove(curr.size()-1);
            return;
        }
        func(root.left,sum,targetSum,curr,ans);
        func(root.right,sum,targetSum,curr,ans);
        curr.remove(curr.size()-1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        func(root,0,targetSum,curr,ans);
        return ans;
    }
}