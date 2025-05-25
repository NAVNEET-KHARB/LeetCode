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
class BSTIterator {
    ArrayList<Integer> inorder;
    int index;
    private void inOrder(TreeNode root){
        if(root == null) return;
        inOrder(root.left);
        inorder.add(root.val);
        inOrder(root.right);
    }
    public BSTIterator(TreeNode root) {
        inorder = new ArrayList<>();
        index = -1;
        inOrder(root);
    }
    
    public int next() {
        index++;
        return inorder.get(index);
    }
    
    public boolean hasNext() {
        return index<inorder.size()-1;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */