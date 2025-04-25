/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    private int[] getNodeVal(String str, int ind){
        if(str.charAt(ind) == '#')return new int[]{-1001, ind + 2};
        int val = 0;
        boolean isNegative = false;
        if (str.charAt(ind) == '-') {
            isNegative = true;
            ind++;
        }
        while (str.charAt(ind) != ',') {
            val = val * 10 + (str.charAt(ind) - '0');
            ind++;
        }
        if (isNegative) val = -val;
        int[] ans = new int[2];
        ans[0] = val;
        ans[1] = ind+1;
        return ans;
    }
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder encoded = new StringBuilder();
        if(root == null) return encoded.toString();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            TreeNode curr = q.poll();
            if(curr == null) encoded.append("#,");
            else encoded.append(curr.val).append(',');
            if(curr != null){
                q.add(curr.left);
                q.add(curr.right);
            }
        }
        return encoded.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data.length() == 0) return null;
        int ind = 0;
        int[] arr = getNodeVal(data,ind);
        TreeNode root = new TreeNode(arr[0]);
        ind = arr[1];
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            TreeNode curr = q.poll();
            arr = getNodeVal(data,ind);
            ind = arr[1];
            if(arr[0] == -1001) curr.left = null;
            else{
                TreeNode left = new TreeNode(arr[0]);
                curr.left = left;
                q.add(left);
            }
            arr = getNodeVal(data,ind);
            ind = arr[1];
            if(arr[0] == -1001) curr.right = null;
            else{
                TreeNode right = new TreeNode(arr[0]);
                curr.right = right;
                q.add(right);
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode val = deser.deserialize(ser.serialize(root));