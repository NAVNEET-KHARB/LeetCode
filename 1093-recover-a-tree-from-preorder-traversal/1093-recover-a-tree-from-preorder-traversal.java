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
    public TreeNode recoverFromPreorder(String traversal) {
        Stack<TreeNode> st = new Stack<>();
        int ind = 0;
        while(ind<traversal.length()){
            int depth = 0;
            while(ind<traversal.length() && traversal.charAt(ind) == '-'){
                depth++;
                ind++;
            }
            int data = 0;
            while(ind<traversal.length() && Character.isDigit(traversal.charAt(ind))){
                data = data*10 + (traversal.charAt(ind)-'0');
                ind++;
            }
            TreeNode node = new TreeNode(data);
            while(st.size()>depth) st.pop();
            if(!st.empty()){
                if(st.peek().left == null) st.peek().left = node;
                else st.peek().right = node;
            }
            st.push(node);
        }
        while(st.size()>1) st.pop();
        return st.peek();
    }
}