/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
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
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        HashMap<TreeNode,TreeNode> parents = new HashMap<>();
        markParents(root,parents);
        HashMap<TreeNode,Boolean> vis = new HashMap<>();
        Queue<TreeNode> q = new LinkedList<>();
        int currDist = 0;
        q.add(target);
        vis.put(target,true);
        while(!q.isEmpty()){
            if(currDist == k) break;
            int n = q.size();
            currDist++;
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
        List<Integer> ans = new ArrayList<>();
        while(!q.isEmpty()){
            ans.add(q.poll().val);
        }
        return ans;
    }
}