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
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }

    int height(TreeNode* root){
        if (root == NULL){
            return 0;
        }

        int L = height(root->left);
        int R = height(root->right);

        diameter = max(diameter, L+R);

        return 1 + max (L,R);
    }
};
