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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode curr = head, prev = null;
        while(curr!=null && curr.next!=null){
            if(curr.val == curr.next.val){
                int data = curr.val;
                while(curr!= null && curr.val == data) curr = curr.next;
                if(prev == null) head = curr;
                else prev.next = curr;
            }else{
                prev = curr;
                curr = curr.next;
            }
        }
        return head;
    }
}