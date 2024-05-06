#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Runtime - 260ms || Memory - 159.64 MB
class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        ListNode *prev = nullptr, *curr = head;
        while (curr != nullptr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode *dummyHead = new ListNode(-1);
        ListNode *tempPrev = dummyHead;
        curr = prev;

        while (curr != nullptr)
        {
            if (curr->val >= tempPrev->val)
            {
                tempPrev->next = curr;
                tempPrev = curr;
                curr = curr->next;
            }
            else
            {
                curr = curr->next;
            }
        }
        tempPrev->next = nullptr;

        ListNode *newPrev = nullptr, *newCurr = dummyHead->next;
        while (newCurr != nullptr)
        {
            ListNode *next = newCurr->next;
            newCurr->next = newPrev;
            newPrev = newCurr;
            newCurr = next;
        }

        return newPrev;
    }
};

int main()
{
    return 0;
}