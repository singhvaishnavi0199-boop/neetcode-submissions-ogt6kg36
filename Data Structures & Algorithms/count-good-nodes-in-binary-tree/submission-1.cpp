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

        queue<pair<TreeNode*, int>> que;
        que.push({root, INT_MIN});
        int res = 0;
        while(!que.empty()){
            auto [node, maxValue] = que.front();
            que.pop();

            if(node->val >= maxValue){
                res++;
            }

            if(node->right){
                que.push({node->right, max(node->val, maxValue)});
            }

            if(node->left){
                que.push({node->left, max(node->val, maxValue)});
            }
        }
        return res;
    }
};
