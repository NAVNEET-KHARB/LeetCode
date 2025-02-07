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
    ListNode reverse(ListNode head){
        if(head == null || head.next == null) return head;
        ListNode curr = head, prev = null;
        while(curr!=null){
            ListNode nex = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null || head.next == null) return head;
        ListNode curr = head, prevH = head, prevTail = null;
        int temp = k;
        while(curr!=null){
            temp--;
            if(temp == 0){
                ListNode nex = curr.next;
                temp = k;
                curr.next = null;
                ListNode tail = reverse(prevH);
                if(prevH == head) head = tail;
                if(prevTail != null) prevTail.next = tail;
                prevTail = prevH;
                prevH.next = nex;
                curr = prevH;
                prevH = nex;
            }
            curr = curr.next;
        }
        return head;
    }
}