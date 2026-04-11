/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return same(p,q);
    }

    bool same(TreeNode* p, TreeNode* q){
        if (p==NULL && q==NULL){
            return true;
        }
        if (p != NULL && q !=NULL && p->val == q->val){
            return same(p->left, q->left) && same(p->right, q->right);
        }else{
            return false;
        }
    }

};