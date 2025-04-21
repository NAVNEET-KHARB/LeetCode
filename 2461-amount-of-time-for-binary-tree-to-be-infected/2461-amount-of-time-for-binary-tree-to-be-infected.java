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
    public void markParents(TreeNode root, HashMap<TreeNode,TreeNode> parents){
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            TreeNode curr = q.poll();
            if(curr.left != null){
                parents.put(curr.left,curr);
                q.add(curr.left);
            }
            if(curr.right != null){
                parents.put(curr.right,curr);
                q.add(curr.right);
            }
        }
    }
    public TreeNode getTarget(TreeNode root, int target){
        if(root.val == target) return root;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            TreeNode curr = q.poll();
            if(curr.left != null){
                if(curr.left.val == target) return curr.left;
                q.add(curr.left);
            }
            if(curr.right != null){
                if(curr.right.val == target) return curr.right;
                q.add(curr.right);
            }
        }
        return null;
    }
    public int amountOfTime(TreeNode root, int start) {
        HashMap<TreeNode,TreeNode> parents = new HashMap<>();
        HashMap<TreeNode,Boolean> vis = new HashMap<>();
        markParents(root, parents);
        TreeNode startNode = getTarget(root,start);
        Queue<TreeNode> q = new LinkedList<>();
        int time = -1;
        vis.put(startNode,true);
        q.add(startNode);
        while(!q.isEmpty()){
            time++;
            int n = q.size();
            for(int i = 0; i<n; i++){
                TreeNode curr = q.poll();
                if(curr.left != null && !vis.containsKey(curr.left)){
                    vis.put(curr.left,true);
                    q.add(curr.left);
                }
                if(curr.right != null && !vis.containsKey(curr.right)){
                    vis.put(curr.right,true);
                    q.add(curr.right);
                }
                if(parents.containsKey(curr) && !vis.containsKey(parents.get(curr))){
                    vis.put(parents.get(curr),true);
                    q.add(parents.get(curr));
                }
            }
        }
        return time;
    }
}