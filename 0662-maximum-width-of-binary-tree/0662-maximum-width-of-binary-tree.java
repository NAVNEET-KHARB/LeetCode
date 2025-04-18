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
class Pair<P,S>{
    P key;
    S value;
    Pair(P key, S value){
        this.key = key;
        this.value = value;
    }
    P getKey(){
        return this.key;
    }
    S getValue(){
        return this.value;
    }
}
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if(root == null) return 0;
        Queue<Pair<TreeNode,Integer>> q = new LinkedList<>();
        q.add(new Pair(root,0));
        int ans = 0;
        while(!q.isEmpty()){
            int n = q.size();
            int mmin = q.peek().getValue();
            int first = 0, last = 0;
            for(int i = 0; i<n; i++){
                Pair<TreeNode,Integer> p = q.poll();
                TreeNode node = p.getKey();
                int currVal = p.getValue()-mmin;
                if(i == 0) first = currVal;
                if(i == n-1) last = currVal;
                if(node.left != null) q.add(new Pair(node.left,2*currVal+1));
                if(node.right != null) q.add(new Pair(node.right,2*currVal+2));
            }
            ans = Math.max(ans,last-first+1);
        }
        return ans;
    }
}