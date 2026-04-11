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
    void reorderList(ListNode* head) {
        
        //find the middle node
        ListNode *slow = head; //mid point
        ListNode *fast = head;
        while(fast->next !=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *midHead = slow->next;

        //reverse last half
        slow->next = nullptr;

        ListNode *prev = nullptr;
        ListNode *curr = midHead;
        while(curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev= curr;
            curr = temp;
        }

        //merge the lists
        ListNode *list1 = head;
        ListNode *list2 = prev;
        while(list2 != nullptr){
            ListNode *temp1 = list1->next;
            ListNode *temp2 = list2->next;
            list1->next = list2;
            list2->next = temp1;
            list1 = temp1;
            list2 = temp2;
        }

    }
};
