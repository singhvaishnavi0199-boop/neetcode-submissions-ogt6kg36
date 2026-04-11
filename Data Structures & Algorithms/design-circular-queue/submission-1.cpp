class ListNode {
public:
    int val;
    ListNode *prev;
    ListNode *next;
    ListNode(int val){
        this -> val = val;
        this -> next = NULL;
        this -> prev = NULL;
    }

};

class MyCircularQueue {
    ListNode *head;
    ListNode *tail;
    int capacity;
    int entries;

public:
    MyCircularQueue(int k) {
        head = new ListNode(-1);
        tail = new ListNode(-1);
        this ->capacity = k;
        entries = 0;
        head -> next = tail;
        tail -> prev = head;
    }
    
    bool enQueue(int value) {
        if (entries == capacity){
            return false;
        }
        ListNode *temp = new ListNode(value);
        temp->next = head ->next;
        temp->prev = head;
        head ->next = temp;
        temp->next-> prev = temp;
        entries++;
        return true;

    }
    
    bool deQueue() {
        if (entries > 0){
            ListNode *temp = tail-> prev;
            temp->prev->next = tail;
            tail->prev = temp->prev;
            delete temp;
            entries--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(entries>0){
            return tail->prev->val;
        }
        return -1;
    }
    
    int Rear() {
        if (entries > 0){
            return head->next->val;
        }
        return -1;
    }
    
    bool isEmpty() {
        if (entries == 0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if (entries == capacity){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */