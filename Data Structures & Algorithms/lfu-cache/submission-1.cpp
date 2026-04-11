class LinkedList{
public:
    int key;
    int val;
    LinkedList *prev;
    LinkedList *next;

    LinkedList (int key, int val){
        this -> key = key;
        this -> val = val;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

class LFUCache {
public:

    int capacity;
    unordered_map <int , pair<int, LinkedList*>> cache;
    LinkedList *head;
    LinkedList *tail;

    LFUCache(int capacity) {
        this -> capacity = capacity;
        cache.clear();
        head = new LinkedList (0,0);
        tail = new LinkedList (0,0);
        head -> next = tail;
        tail -> prev = head;
    }

    void remove (LinkedList *node){
        LinkedList *prevNode = node -> prev;
        LinkedList *nextNode = node -> next;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }

    void insert (LinkedList *node){
        node -> prev = head;
        node -> next = head -> next;
        head -> next -> prev = node;
        head -> next = node;
    }
    
    int get(int key) {
        if (!cache.count(key)){
            return -1;
        }

        cache[key].first++;
        LinkedList *node = cache[key].second;
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (!cache.count(key)){
            if (cache.size() == capacity){
                int lfu = INT_MAX;
                for (auto &it : cache) {
                    lfu = min (lfu, it.second.first);
                }

                LinkedList *currNode = tail->prev;
                while(currNode != head){
                    if(cache[currNode->key].first == lfu){
                        remove(currNode);
                        cache.erase(currNode->key);
                        delete currNode;
                        break;
                    }
                    currNode = currNode -> prev;
                }
                // traverse from tail node to get the first node with freq = lfu
                // remove that node
                // new node
                // insert node 
                // map 
            }

            LinkedList *newNode = new LinkedList (key, value);
            insert(newNode);
            cache[key] = {1, newNode};
        }else{
            cache[key].first++;
            LinkedList *node = cache[key].second;
            node -> val = value;
            remove(node);
            insert(node);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */