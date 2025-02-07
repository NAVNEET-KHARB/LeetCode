/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) return null;
        Node curr = head;
        while(curr!=null){
            Node newN = new Node(curr.val);
            newN.next = curr.next;
            curr.next= newN;
            curr = curr.next.next;
        }
        curr = head;
        while(curr!=null){
            Node copy = curr.next;
            if(curr.random!=null) copy.random = curr.random.next;
            else copy.random = null;
            curr = curr.next.next;
        }
        Node dummy = new Node(-1);
        Node temp = dummy;
        curr = head;
        while(curr!=null){
            temp.next = curr.next;
            curr.next = curr.next.next;
            curr = curr.next;
            temp = temp.next;
        }
        return dummy.next;
    }
}