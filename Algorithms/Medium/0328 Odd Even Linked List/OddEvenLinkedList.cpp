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

// Runtime - 4ms || Memory - 14.06 MB
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = head->next;
        while (even != NULL && even->next != NULL)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

// Runtime - 8ms || Memory - 14.17 MB
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        vector<int> arr;
        ListNode *temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp)
            arr.push_back(temp->val);
        temp = head->next;
        while (temp != NULL && temp->next != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp)
            arr.push_back(temp->val);
        temp = head;
        int index = 0;
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