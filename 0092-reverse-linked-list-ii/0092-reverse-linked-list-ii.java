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
        ListNode curr = head;
        ListNode prev = null;
        while(curr!=null){
            ListNode nex = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode curr = head, leftN = null, rightN = null;
        ListNode leftN1 = null, rightN1 = null;
        while(curr!=null){
            left--;
            right--;
            if(left == 1) leftN1 = curr;
            if(left == 0) leftN = curr;
            if(right == 0){
                rightN1 = curr.next;
                rightN = curr;
                break;
            }
            curr = curr.next;
        }
        rightN.next = null;
        rightN = reverse(leftN);
        if(leftN1!=null) leftN1.next = rightN;
        leftN.next = rightN1;
        return (leftN1 == null)?rightN:head;
    }
}