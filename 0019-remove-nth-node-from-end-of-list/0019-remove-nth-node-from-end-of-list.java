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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode curr = head;
        int sz = 0;
        while(curr!=null){
            sz++;
            curr = curr.next;
        }
        if(sz == n) return head.next;
        sz -= n;
        curr = head;
        while(sz>1){
            sz--;
            curr = curr.next;
        }
        curr.next = curr.next.next;
        return head;
    }
}