#include <bits/stdc++.h>
using namespace std;

// Runtime - 4ms || Memory - 11.54 MB
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *temp = head;
        ListNode *prev = NULL;
        while (temp != NULL)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};

int main()
{
    return 0;
}