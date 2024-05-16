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

// Runtime - 539ms || Memory - 298.26 MB
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        fast = fast->next->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = slow->next->next;
        delete mid;
        return head;
    }
};

// Runtime - 520ms || Memory - 298.22 MB
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *temp = head;
        int n = 0;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }
        int res = n / 2;
        temp = head;
        while (temp != NULL)
        {
            res--;
            if (res == 0)
            {
                ListNode *mid = temp->next;
                temp->next = temp->next->next;
                delete mid;
                return head;
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