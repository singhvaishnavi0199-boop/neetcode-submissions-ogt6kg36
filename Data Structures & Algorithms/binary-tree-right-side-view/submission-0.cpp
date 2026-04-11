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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL){
            return result;
        }

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int qsize = que.size();
            for(int i = 0; i< qsize ; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
                if(i == qsize-1){
                    result.push_back(node->val);
                }
            }
        }
        return result;
    }
};
