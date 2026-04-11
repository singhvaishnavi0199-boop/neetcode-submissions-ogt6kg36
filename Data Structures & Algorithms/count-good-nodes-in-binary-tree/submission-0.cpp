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
    int goodNodes(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        return dfs(root, root->val);
    }

    int dfs(TreeNode* node, int maxValue){
        if (node == NULL){
            return 0;
        }

        int res = 0;
        if (node->val >= maxValue){
           res++;  
        }
        maxValue = max (maxValue, node->val);
        res += dfs(node->left, maxValue);
        res += dfs(node->right, maxValue);

        return res;
    }
};
