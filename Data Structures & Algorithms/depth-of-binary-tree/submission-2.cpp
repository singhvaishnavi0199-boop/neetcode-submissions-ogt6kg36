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
       int res = 0;
       stack<pair<TreeNode* , int>> st;
       st.push({root, 1});

       while(!st.empty()){
        auto currNode = st.top();
        st.pop();
        TreeNode *node = currNode.first;
        int depth = currNode.second;
        res = max(res, depth);

        
        if (node->left){
            st.push({node->left, depth+1});
        }
        if (node->right){
            st.push({node->right, depth+1});
        }
        
       }

       return res;
    }
};
