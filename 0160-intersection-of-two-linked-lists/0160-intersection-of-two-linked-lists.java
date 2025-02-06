/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    ListNode coll(ListNode smaller, ListNode greater, int diff){
        while(diff>0){
            diff--;
            greater = greater.next;
        }
        while(smaller!=greater){
            smaller = smaller.next;
            greater = greater.next;
        }
        return smaller;
    }
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode curr = headA;
        int n1 = 0, n2 = 0;
        while(curr!=null){
            n1++;
            curr = curr.next;
        }
        curr = headB;
        while(curr!=null){
            n2++;
            curr = curr.next;
        }
        if(n2>n1) return coll(headA,headB,n2-n1);
        return coll(headB,headA,n1-n2);
    }
}