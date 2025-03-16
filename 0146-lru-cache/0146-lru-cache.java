class LRUCache {
    class Node{
        int key, val;
        Node next, prev;
        Node(int key, int val){
            this.key = key;
            this.val = val;
            this.next = null;
            this.prev = null;
        }
    }
    int capacity;
    HashMap<Integer,Node> mpp;
    Node head, tail;
    public LRUCache(int capacity) {
        this.capacity = capacity;
        mpp = new HashMap<>();
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        tail.prev = head;
        head.next = tail;
    }
    
    public void addNode(Node node){
        node.next = head.next;
        head.next.prev = node;
        node.prev = head;
        head.next = node;
    }

    public void removeNode(Node node){
        node.next.prev = node.prev;
        node.prev.next = node.next;
    }

    public int get(int key) {
        if(mpp.containsKey(key)){
            Node node = mpp.get(key);
            int value = node.val;
            mpp.remove(key);
            removeNode(node);
            addNode(node);
            mpp.put(key,node);
            return value;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if(mpp.containsKey(key)){
            Node node = mpp.get(key);
            mpp.remove(key);
            removeNode(node);
        }
        if(mpp.size() == capacity){
            mpp.remove(tail.prev.key);
            removeNode(tail.prev);
        }
        Node node = new Node(key,value);
        addNode(node);
        mpp.put(key,node);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */