/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map <Node* , Node*> oldToNew;
        oldToNew[NULL] = NULL;
        Node *curr = head;
        while(curr){
            if (oldToNew.find(curr) == oldToNew.end()){
                Node *temp = new Node(0);
                oldToNew[curr] = temp;
            }
            oldToNew[curr]->val = curr->val;

            if (oldToNew.find(curr->next) == oldToNew.end()){
                Node *temp = new Node(0);
                oldToNew[curr->next] = temp;
            }
            oldToNew[curr]->next = oldToNew[curr->next];

            if (oldToNew.find(curr->random) == oldToNew.end()){
                Node *temp = new Node(0);
                oldToNew[curr->random] = temp;
            }
            oldToNew[curr]->random = oldToNew[curr->random];

            curr = curr->next;
        }
        return oldToNew[head];
    }
};
