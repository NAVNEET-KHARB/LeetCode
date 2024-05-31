#include <bits/stdc++.h>
using namespace std;

// Runtime - 7ms || Memory - 12.84 MB Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *createNodes(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
        return head;
    }
    Node *connRandom(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *copyNode = temp->next;
            if (temp->random)
                copyNode->random = temp->random->next;
            else
                copyNode->random = NULL;
            temp = temp->next->next;
        }
        return head;
    }
    Node *connNext(Node *head)
    {
        Node *temp = head;
        Node *dNode = new Node(-1);
        Node *res = dNode;
        while (temp != NULL)
        {
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return dNode->next;
    }
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;
        head = createNodes(head);
        head = connRandom(head);
        return connNext(head);
    }
};

int main()
{
    return 0;
}