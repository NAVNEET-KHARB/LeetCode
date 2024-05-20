#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Runtime - 44ms || Memory - 17.08 MB
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while (temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
            if (temp1 == temp2)
                return temp1;
            if (temp1 == NULL)
                temp1 = headB;
            if (temp2 == NULL)
                temp2 = headA;
        }
        return temp1;
    }
};

// Runtime - 38ms || Memory - 16.95 MB
class Solution
{
public:
    ListNode *collPoint(ListNode *smaller, ListNode *greater, int diff)
    {
        while (diff)
        {
            diff--;
            greater = greater->next;
        }
        while (smaller != greater)
        {
            smaller = smaller->next;
            greater = greater->next;
        }
        return smaller;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        int n1 = 0, n2 = 0;
        while (temp1 != NULL)
        {
            n1++;
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            n2++;
            temp2 = temp2->next;
        }
        if (n2 > n1)
        {
            return collPoint(headA, headB, n2 - n1);
        }
        return collPoint(headB, headA, n1 - n2);
    }
};

// Runtime - 36ms || Memory - 21.57 MB
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, int> mpp;
        ListNode *temp = headA;
        while (temp != NULL)
        {
            mpp[temp] = 1;
            temp = temp->next;
        }
        temp = headB;
        while (temp != NULL)
        {
            if (mpp.find(temp) != mpp.end())
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};

int main()
{
    return 0;
}