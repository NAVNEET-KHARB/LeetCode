#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Runtime - 3ms || Memory - 10.10 MB
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

// Runtime - 7ms || Memory - 13.50 MB
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_map<ListNode *, int> mpp;
        ListNode *temp = head;
        while (temp != NULL)
        {
            if (mpp.find(temp) != mpp.end())
                return temp;
            mpp[temp] = 1;
            temp = temp->next;
        }
        return NULL;
    }
};

int main()
{
    return 0;
}