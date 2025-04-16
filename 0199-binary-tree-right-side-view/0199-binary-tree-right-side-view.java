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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if(root == null) return ans;
        TreeMap<Integer,Integer> mpp = new TreeMap<>();
        Queue<Pair<TreeNode,Integer>> q = new LinkedList<>();
        q.add(new Pair(root,0));
        while(!q.isEmpty()){
            Pair<TreeNode,Integer> p = q.poll();
            TreeNode node = p.getKey();
            int level = p.getValue();
            mpp.put(level,node.val);
            if(node.left != null) q.add(new Pair(node.left,level+1));
            if(node.right != null) q.add(new Pair(node.right,level+1));
        }
        for(Integer value : mpp.values()) ans.add(value);
        return ans;
    }
}