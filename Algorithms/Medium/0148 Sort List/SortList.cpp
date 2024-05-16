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

// Runtime - 137ms || Memory - 73.52 MB
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *t1 = list1;
        ListNode *t2 = list2;
        ListNode *dNode = new ListNode(-1);
        ListNode *temp = dNode;
        while (t1 != NULL && t2 != NULL)
        {
            if (t1->val < t2->val)
            {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        if (t1 != NULL)
            temp->next = t1;
        else
            temp->next = t2;
        return dNode->next;
    }
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *middle = findMiddle(head);
        ListNode *leftHead = head;
        ListNode *rightHead = middle->next;
        middle->next = NULL;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return mergeTwoLists(leftHead, rightHead);
    }
};

// Runtime - 120ms || Memory - 56.88 MB
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        vector<int> arr;
        ListNode *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        int index = 0;
        temp = head;
        while (temp != NULL)
        {
            temp->val = arr[index];
            index++;
            temp = temp->next;
        }
        return head;
    }
};

int main()
{
    return 0;
}