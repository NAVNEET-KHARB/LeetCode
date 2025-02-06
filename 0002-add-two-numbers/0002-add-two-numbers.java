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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode temp1 = l1, temp2 = l2;
        ListNode dummy = new ListNode(-1), curr = dummy;
        int carry = 0;
        while(temp1!=null || temp2!=null){
            int sum = carry;
            if(temp1!=null) sum += temp1.val;
            if(temp2!=null) sum += temp2.val;
            ListNode newN = new ListNode(sum%10);
            carry = sum/10;
            curr.next = newN;
            curr = curr.next;
            if(temp1!=null) temp1 = temp1.next;
            if(temp2!=null) temp2 = temp2.next;
        }
        if(carry==1) curr.next = new ListNode(1);
        return dummy.next;
    }
}