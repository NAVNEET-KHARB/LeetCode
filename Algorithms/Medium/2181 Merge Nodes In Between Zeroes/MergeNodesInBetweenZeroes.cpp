#include <bits/stdc++.h>
using namespace std;

// Runtime - 429ms || Memory - 278.08 MB
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *temp = head->next;
        int value = 0;
        ListNode *dNode = new ListNode(-1);
        ListNode *tail = dNode;
        while (temp != NULL)
        {
            if (temp->val == 0)
            {
                ListNode *node = new ListNode(value);
                tail->next = node;
                tail = tail->next;
                value = 0;
            }
            value += temp->val;
            temp = temp->next;
        }
        return dNode->next;
    }
};

int main()
{
    return 0;
}