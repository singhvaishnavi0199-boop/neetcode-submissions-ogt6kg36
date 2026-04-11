/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode (0);
        ListNode *head = dummy;
        priority_queue <pair<int, ListNode*> , vector<pair<int, ListNode*>> , greater<>> minHeap;

        for(int i = 0; i<lists.size(); i++){
            minHeap.push({lists[i]->val,lists[i]});
        }

        while(!minHeap.empty()){
            auto [val, node] = minHeap.top();
            minHeap.pop();
            dummy->next = node;
            dummy = node;

            if (node->next != NULL){
                minHeap.push({node->next->val, node->next});
            }
        }

        return head->next;
    }

};
