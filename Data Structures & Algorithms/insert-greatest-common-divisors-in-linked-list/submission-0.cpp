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
private:
    int gcd (int a, int b){
        while (b> 0){
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL){
            return NULL;
        }

        ListNode *prev = head;
        ListNode *curr = head->next;
        while(prev && curr){
            int val = gcd(prev->val, curr->val);
            ListNode* node = new ListNode(val);
            prev->next = node;
            node->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};