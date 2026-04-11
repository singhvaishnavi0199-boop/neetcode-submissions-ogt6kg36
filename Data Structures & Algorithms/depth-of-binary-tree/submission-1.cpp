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
    int maxDepth(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        int depth = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int qsize = q.size();
            for(int i = 0 ; i< qsize ; i++){
                TreeNode *currNode = q.front();
                q.pop();
                if (currNode -> left){
                    q.push(currNode -> left);
                }
                if (currNode -> right){
                    q.push(currNode -> right);
                }
            }
            depth++;
        }

        return depth;
    }
};
