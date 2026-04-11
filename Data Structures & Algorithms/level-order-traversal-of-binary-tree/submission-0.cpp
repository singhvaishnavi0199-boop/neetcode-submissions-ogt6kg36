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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int queSize = que.size();
            vector<int> levelRes;
            for(int i = 0; i< queSize ; i++){
                TreeNode* node = que.front();
                levelRes.push_back(node->val);
                que.pop();
                if (node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }
            result.push_back(levelRes);
        }

        return result;
    }
};
