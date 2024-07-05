#include <bits/stdc++.h>
using namespace std;

// Runtime - 387ms || Memory - 181.01 MB
class LFUCache
{
    class Node
    {
    public:
        int key;
        int value;
        Node *next;
        Node *prev;
        int cnt;
        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
            this->cnt = 1;
        }
    };

    class List
    {
    public:
        int size;
        Node *head;
        Node *tail;
        List()
        {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void addNode(Node *newNode)
        {
            Node *temp = head->next;
            newNode->next = temp;
            newNode->prev = head;
            head->next = newNode;
            temp->prev = newNode;
            size++;
        }

        void deleteNode(Node *delNode)
        {
            Node *delNext = delNode->next;
            Node *delPrev = delNode->prev;
            delNext->prev = delPrev;
            delPrev->next = delNext;
            size--;
        }
    };

    map<int, Node *> keyNode;
    map<int, List *> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        {
            minFreq++;
        }

        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end())
        {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->addNode(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxSizeCache == 0)
        {
            return;
        }
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            if (curSize == maxSizeCache)
            {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->deleteNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
            {
                listFreq = freqListMap[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->addNode(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    return 0;
}