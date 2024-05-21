#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Runtime - 22ms || Memory - 76.08 MB
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *dummyNode = new ListNode(-1);
        ListNode *curr = dummyNode;
        int carry = 0;
        while (temp1 != NULL || temp2 != NULL)
        {
            int sum = carry;
            if (temp1)
                sum += temp1->val;
            if (temp2)
                sum += temp2->val;
            ListNode *newNode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newNode;
            curr = curr->next;
            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }
        if (carry)
        {
            ListNode *newNode = new ListNode(1);
            curr->next = newNode;
        }
        return dummyNode->next;
    }
};

int main()
{
    return 0;
}