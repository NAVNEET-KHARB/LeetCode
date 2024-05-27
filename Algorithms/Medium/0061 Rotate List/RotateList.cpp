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

// Runtime - 0ms || Memory - 15.28 MB
class Solution
{
public:
    ListNode *nthNode(ListNode *temp, int n)
    {
        int cnt = 1;
        while (temp != NULL)
        {
            if (cnt == n)
                break;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || k == 0)
            return head;
        ListNode *lastNode = head;
        int len = 1;
        while (lastNode->next != NULL)
        {
            len++;
            lastNode = lastNode->next;
        }
        k = k % len;
        if (k == 0)
            return head;
        lastNode->next = head;
        ListNode *newLastNode = nthNode(head, len - k);
        head = newLastNode->next;
        newLastNode->next = NULL;
        return head;
    }
};

int main()
{
    return 0;
}