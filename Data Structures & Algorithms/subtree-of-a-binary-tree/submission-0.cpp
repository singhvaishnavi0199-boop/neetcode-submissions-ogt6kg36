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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot != NULL || root != NULL && subRoot == NULL){
            return false;
        }
        if (root != NULL && subRoot != NULL && root->val == subRoot->val){
            if (sameTree(root, subRoot)){
                return true;
            }
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool sameTree(TreeNode* root1, TreeNode* root2){
        if (root1 == NULL && root2 == NULL){
            return true;
        }

        if (root1 != NULL && root2 != NULL && root1 ->val == root2 ->val){
            return sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right);
        }else{
            return false;
        }
    }
};
