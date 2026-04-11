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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }

    TreeNode* dfs(TreeNode* root, int target){
        if (root == NULL){
            return NULL;
        }

        root ->left = dfs(root->left, target);
        root ->right = dfs(root ->right, target);

        if (root ->left == NULL && root->right == NULL && root->val == target){
            return NULL;
        }
        
        // if (root->left!= NULL && root->left->val == target){
        //     root->left = NULL;
        // }

        // if(root->right!= NULL && root ->right->val == target){
        //     root-> right = NULL;
        // }

        // if (root ->left == NULL && root->right == NULL){
        //     if (root -> val == target){
        //         return NULL;
        //     }
        // }

        return root;

        
    }
};