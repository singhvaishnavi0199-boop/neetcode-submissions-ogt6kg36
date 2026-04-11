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

    int sumList (ListNode* head){
        ListNode *curr = head;
        int multiplier = 1;
        int sum = 0;
        while(curr){
            sum += (curr->val) * multiplier;
            multiplier *= 10;
            curr = curr->next;
        }
        // cout<<sum;
        return sum;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = sumList(l1) + sumList(l2);
        ListNode *head = new ListNode(0);
        ListNode *prev = head;
        if (sum == 0){
            return head;
        }
        while(sum > 0){
            int val = sum % 10;
            cout<< val<<endl;
            ListNode *temp = new ListNode(val);
            prev -> next = temp;
            prev = temp;
            sum = sum/10;
        }

        return head->next;
    }
};
