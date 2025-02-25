/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverse(ListNode head){
        ListNode curr = head, prev = null;
        while(curr!=null){
            ListNode nex = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    public void reorderList(ListNode head) {
        if(head.next == null || head.next.next == null) return;
        ListNode l1 = head, l2 = head.next;
        while(l2!=null && l2.next!=null){
            l1 = l1.next;
            l2 = l2.next.next;
        }
        l2 = reverse(l1.next);
        l1.next = null;
        l1 = head;
        ListNode dHead = new ListNode(-1), curr = dHead;
        while(l1!= null && l2!=null){
            curr.next = l1;
            l1 = l1.next;
            curr = curr.next;
            curr.next = l2;
            curr = curr.next;
            l2 = l2.next;
        }
        if(l1!=null) curr.next = l1;
        head = dHead.next;
    }
}