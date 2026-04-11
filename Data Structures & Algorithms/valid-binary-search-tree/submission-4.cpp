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
    bool isValidBST(TreeNode* root) {
        if (root == NULL){
            return true;
        }

        queue<tuple<TreeNode*, int, int>> que;
        que.push(make_tuple(root, INT_MIN, INT_MAX)); // node, lower, upper

        while(!que.empty()){
            auto [node, lower, upper] = que.front();
            que.pop();

            if (node->val <= lower || node->val >= upper){
                return false;
            }

            if(node->left){
                que.push(make_tuple(node->left, lower, node->val));
            }

             if(node->right){
                que.push(make_tuple(node->right, node->val, upper));
            }
        }
        return true;
    }
};
