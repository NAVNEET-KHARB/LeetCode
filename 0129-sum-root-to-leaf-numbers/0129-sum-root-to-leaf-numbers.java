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
    public void preOrder(TreeNode root, int curr, ArrayList<Integer> arr){
        if(root == null) return;
        curr = curr*10 + root.val;
        if(root.left == null && root.right == null){
            arr.add(curr);
            return;
        }
        preOrder(root.left,curr,arr);
        preOrder(root.right,curr,arr);
    }
    public int sumNumbers(TreeNode root) {
        ArrayList<Integer> arr = new ArrayList<>();
        int curr = 0;
        preOrder(root,curr,arr);
        int ans = 0;
        for(int num : arr) ans += num;
        return ans;
    }
}