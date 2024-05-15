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

// Runtime - 7ms || Memory - 13.37 MB
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if (fast == NULL)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode *slow = head;
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};

int main()
{
    return 0;
}