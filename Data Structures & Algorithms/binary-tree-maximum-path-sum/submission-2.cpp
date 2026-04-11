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
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root){
        if (root == NULL){
            return 0;
        }

        // not including bad paths
        int left = max(dfs(root->left),0);
        int right = max(dfs(root->right),0);

        // with split

        int curr = root->val + left + right;

        res = max(curr, res);

        // value up
        return root->val + max(left, right);
    }
};
