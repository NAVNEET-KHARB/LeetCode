#include <bits/stdc++.h>
using namespace std;

// Runtime - 270ms || Memory - 168.08 MB
static auto speedup = []()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();
class LRUCache
{
private:
    struct Node
    {
        int key, val;
        Node *pre;
        Node *nex;
        Node(int k, int v) : key(k), val(v), pre(nullptr), nex(nullptr) {}
    };
    unordered_map<int, Node *> mp;
    Node *head;
    Node *tail;
    int capct;
    void add(Node *node)
    {
        node->nex = head->nex;
        node->nex->pre = node;
        node->pre = head;
        head->nex = node;
    }
    void remove(Node *node)
    {
        node->pre->nex = node->nex;
        node->nex->pre = node->pre;
    }
    void pushtohead(Node *node)
    {
        remove(node);
        add(node);
    }

public:
    LRUCache(int capacity) : capct(capacity)
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->nex = tail;
        tail->pre = head;
    }

    ~LRUCache()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *nt = temp->nex;
            delete temp;
            temp = nt;
        }
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        else
        {
            Node *nd = mp[key];
            pushtohead(nd);
            return nd->val;
        }
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *nd = mp[key];
            nd->val = value;
            pushtohead(nd);
        }
        else
        {
            if (mp.size() >= capct)
            {
                Node *nd = tail->pre;
                mp.erase(nd->key);
                remove(nd);
                delete nd;
            }
            Node *nw = new Node(key, value);
            mp[key] = nw;
            add(nw);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    return 0;
}