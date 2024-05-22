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

// Runtime - 8ms || Memory - 18.60 MB
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy;
        while (current->next != NULL)
        {
            if (current->next->val == val)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
        return dummy->next;
    }
};

// Runtime - 17ms || Memory - 18.80 MB
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return NULL;
        ListNode *temp = head;
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *prevNode = dummyNode;
        while (temp != NULL)
        {
            if (temp->val == val)
            {
                if (temp == head)
                {
                    head = head->next;
                }
                prevNode->next = temp->next;
                delete temp;
                temp = prevNode->next;
            }
            else
            {
                prevNode = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};

int main()
{
    return 0;
}