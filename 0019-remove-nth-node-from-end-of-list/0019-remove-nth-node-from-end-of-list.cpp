/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode* temp = head;
        int cnt = 0;
        while(temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        int res = cnt - n;
        if(res == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        temp = head;
        res--;
        while(res > 0) {
            res--;
            temp = temp->next;
        }
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        return head; 
    }
};