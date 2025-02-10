/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public class Pair<K, V> {
        private K key;
        private V value;
        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }
        public K getKey() {
            return key;
        }
        public V getValue() {
            return value;
        }
    }
    public Node connect(Node root) {
        if(root == null) return null;
        Queue<Pair<Node,Integer>> q = new LinkedList<>();
        q.add(new Pair<>(root,0));
        while(q.size()>0){
            Pair<Node,Integer> nodeP = q.poll();
            Node currNode = nodeP.getKey();
            int level = nodeP.getValue();
            currNode.next = (q.size() == 0 || q.peek().getValue()!=level)?null:q.peek().getKey();
            if(currNode.left!=null) q.add(new Pair<>(currNode.left,level+1));
            if(currNode.right!=null) q.add(new Pair<>(currNode.right,level+1));
        }
        return root;
    }
}