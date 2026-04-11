class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>> res (c, vector<int> (r,0));
        for(int i= 0; i<res.size(); i++){
            for(int j = 0; j< res[0].size(); j++){
                res[i][j] = matrix[j][i];
            }
        }

        return res;
    }
};