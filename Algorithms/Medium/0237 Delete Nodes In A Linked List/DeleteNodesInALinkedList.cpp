#include <bits/stdc++.h>
using namespace std;

// Runtime - 6ms || Memory - 11.26 MB
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main()
{
    return 0;
}