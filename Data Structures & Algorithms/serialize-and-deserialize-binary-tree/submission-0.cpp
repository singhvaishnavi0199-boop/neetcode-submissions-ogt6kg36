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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root, res);
        return join(res, ",");

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> val = split(data, ',');
        int i = 0;
        return dfsDeserialize(val, i);
    }

    void dfsSerialize(TreeNode* root, vector<string>& res){
        if (root == NULL){
            res.push_back("N");
            return;
        }

        res.push_back(to_string(root->val));
        dfsSerialize(root->left, res);
        dfsSerialize(root->right, res);
    }

    string join(const vector<string>& res, string delimiter){
        string st = "";
        for (int i =0; i<res.size(); i++){
            st += res[i];
            if (i!= res.size()-1){
                st += delimiter;
            }
        }
        return st;
    }

    vector<string> split (string data, char delim){
        vector<string> val;
        for(int i =0 ; i<data.size(); i++){
            string curr = "";
            while(i < data.size() && data[i] != delim){
                curr = curr + data[i];
                i++;
            }
            val.push_back(curr);
        }
        return val;
    }

    TreeNode* dfsDeserialize(vector<string>& val, int& i){
        if (val[i] == "N"){
            i++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(val[i]));
        i++;
        node->left = dfsDeserialize(val,i);
        node->right = dfsDeserialize(val,i);
        return node;
    }
};
