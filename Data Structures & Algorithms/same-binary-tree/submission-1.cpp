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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p,q});

        while(!st.empty()){
            auto nodes = st.top();
            st.pop();

            if (nodes.first == NULL && nodes.second == NULL){
                continue;
            }

            if(nodes.first == NULL && nodes.second != NULL ||
                nodes.first != NULL && nodes.second == NULL ||
                nodes.first != NULL && nodes.second != NULL && nodes.first->val != nodes.second->val){
                    return false;
                }else{
                    st.push({nodes.first->left,nodes.second->left});
                    st.push({nodes.first->right, nodes.second->right});
                }
        }
        return true;
    }
};
