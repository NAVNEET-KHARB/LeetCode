#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Runtime - 150ms || Memory - 120.56 MB
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if (head->val > 4) {
            head = new ListNode(0, head);
        }
        ListNode* temp = head;
        while(temp!=NULL){
            temp->val = (temp->val*2)%10;
            if(temp->next!=nullptr && temp->next->val>4){
                temp->val++;
            }
            temp = temp->next;
        }
        return head;
    }
};

int main()
{
    return 0;
}