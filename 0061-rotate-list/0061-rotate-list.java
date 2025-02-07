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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null || k == 0) return head;
        int sz = 0;
        ListNode curr = head;
        while(curr.next!=null){
            sz++;
            curr = curr.next;
        }
        sz++;
        ListNode last = curr;
        k = k%sz;
        if(k == 0) return head;
        sz -= k;
        curr = head;
        while(curr!=null){
            sz--;
            if(sz == 0){
                ListNode nex = curr.next;
                curr.next = null;
                last.next = head;
                return nex;
            }
            curr = curr.next;
        }
        return null;
    }
}