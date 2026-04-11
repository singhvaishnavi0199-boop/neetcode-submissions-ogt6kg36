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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        TreeNode* node = new TreeNode();
        node->val = val;
        insert(root, val, node);
        return root;
    }

    void insert(TreeNode* root, int val, TreeNode* node){
        // if (root == NULL){
        //     root = node;
        //     return;
        // }
        if (root->val < val){
            if (root-> right == NULL){
                root->right = node;
                return;
            }else{
                insert(root->right, val, node);
            }
        }else{
            if (root-> left == NULL){
                root->left = node;
                return;
            }else{
                insert(root->left, val, node);
            }
        }
    }
};