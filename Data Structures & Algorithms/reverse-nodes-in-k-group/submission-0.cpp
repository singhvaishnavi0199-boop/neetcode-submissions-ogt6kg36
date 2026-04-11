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
    ListNode* reverseLinkedList (ListNode* head){
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while(curr){
            ListNode *temp = curr ->next;
            curr ->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

     ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        prev -> next = head;
        ListNode *left = head;
        ListNode *right = head;

        while(right){
            for(int i =1 ;i<k;i++){
                if (right && right->next){
                    right = right->next;
                }else{
                    prev->next = left;
                    return dummy->next;
                }
            }

            ListNode *temp = right ->next;
            right ->next = NULL;
            prev -> next = reverseLinkedList(left);
            prev = left;
            left = temp;
            right = temp;
        }
        return dummy->next;
    }
};
