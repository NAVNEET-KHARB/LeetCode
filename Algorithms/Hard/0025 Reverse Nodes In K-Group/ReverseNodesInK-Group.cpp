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

// Runtime - 10ms || Memory - 15.00 MB
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
    ListNode *getKthNode(ListNode *temp, int k)
    {
        k -= 1;
        while (temp != NULL && k > 0)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *prevNode = NULL;
        while (temp != NULL)
        {
            ListNode *kthNode = getKthNode(temp, k);
            if (kthNode == NULL)
            {
                if (prevNode)
                {
                    prevNode->next = temp;
                }
                break;
            }
            ListNode *nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseList(temp);
            if (temp == head)
            {
                head = kthNode;
            }
            else
            {
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};

int main()
{
    return 0;
}