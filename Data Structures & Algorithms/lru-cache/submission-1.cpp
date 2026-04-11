class LinkedList {

public:
    int key;
    int val; 
    LinkedList *prev;
    LinkedList *next;
    LinkedList(int key, int val){
        this -> key = key;
        this -> val = val;
        this -> prev = NULL;
        this -> next = NULL;
    }
};


class LRUCache {

public:
    int capacity;
    unordered_map<int, LinkedList*> cache;
    LinkedList *head;
    LinkedList *tail;

// head (prev, next) --- tail (prev, next)
// head ->next = tail 
// tail ->prev = head

    LRUCache(int capacity) {
        this -> capacity = capacity;
        cache.clear(); // resize/ start afresh map
        head = new LinkedList(0,0);
        tail = new LinkedList(0,0);
        head -> next = tail;
        tail -> prev = head;
    }

    void remove (LinkedList *node){
        LinkedList *nextNode = node -> next;
        LinkedList *prevNode = node -> prev;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }

    void insert(LinkedList *node){
        node-> next = head->next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
    }
    
    int get(int key) {
        if (cache.count(key)){
            LinkedList *node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (!cache.count(key)){
            LinkedList *newNode = new LinkedList (key, value);
            cache[key] = newNode;
            insert(newNode);
            if (cache.size() > capacity){
                LinkedList *lru = tail->prev;
                remove(lru);
                cache.erase(lru->key);
            }
        }else{
            LinkedList *currNode = cache[key];
            currNode -> val = value;
            remove(currNode);
            insert(currNode);
        }
    }
};
