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

    ListNode* reverseLinkedList(ListNode* head){
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *curr = head;
        ListNode *prev = dummy;
        ListNode *prevLeft = NULL;
        ListNode *leftNode = NULL;
        ListNode *rightNode = NULL;
        for(int i = 1; i<=right ; i++){
            if (i == left){
                prevLeft = prev;
                leftNode = curr;
            }
            if (i == right){
                rightNode = curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        ListNode *rightNext = NULL;
        if (rightNode -> next){
            rightNext = rightNode -> next;
        }

        rightNode ->next = NULL;
        prevLeft-> next = reverseLinkedList(leftNode);
        leftNode->next = rightNext;
        return dummy->next;
    }
};