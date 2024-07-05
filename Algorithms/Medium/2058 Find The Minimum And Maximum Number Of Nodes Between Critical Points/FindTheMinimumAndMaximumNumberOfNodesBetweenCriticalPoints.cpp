#include <bits/stdc++.h>
using namespace std;

// Runtime - 156ms || Memory - 119.82 MB
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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> ans;
        vector<int> c;
        if (head->next->next == NULL)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ListNode *temp = head;
        int a = 2;
        while (temp->next->next)
        {
            if ((temp->next->val > temp->val && temp->next->val > temp->next->next->val) || (temp->next->val < temp->val && temp->next->val < temp->next->next->val))
            {
                c.push_back(a);
            }
            temp = temp->next;
            a++;
        }
        if (c.size() <= 1)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else
        {
            int max = c[c.size() - 1] - c[0];
            int mind = INT_MAX;
            for (int i = 0; i < c.size() - 1; i++)
            {
                mind = min(mind, c[i + 1] - c[i]);
            }
            ans.push_back(mind);
            ans.push_back(max);
            return ans;
        }
    }
};

int main()
{
    return 0;
}