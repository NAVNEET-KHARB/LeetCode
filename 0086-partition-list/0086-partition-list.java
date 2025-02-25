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
    public ListNode partition(ListNode head, int x) {
        if(head == null) return head;
        ListNode dHead = new ListNode(-1);
        ListNode dTail = dHead, curr = head, prev = null, last = null;
        while(curr!=null){
            if(curr.val<x){
                dTail.next = curr;
                if(prev == null) head = curr.next;
                else prev.next = curr.next;
                curr = curr.next;
                dTail = dTail.next;
            }else {
                prev = curr;
                last = curr;
                curr = curr.next;
            }
        }
        if(last!=null) last.next = null;
        dTail.next = head;
        return dHead.next;
    }
}