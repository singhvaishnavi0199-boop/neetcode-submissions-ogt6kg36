class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set <pair<int,int>> zero;
        for(int i = 0; i< matrix.size() ; i++){
            for(int j = 0; j<matrix[0].size() ; j++){
                if (matrix[i][j] == 0){
                    zero.insert({i,j});
                }
                // for(int k = 0; k< matrix.size(); k++){
                //     matrix[k][j] = 0;
                // }
                // for(int k =0; k<matrix[0].size(); k++){
                //     matrix[i][k] = 0;
                // }
            }
        }

        for (auto x : zero) {
            for(int i = 0; i< matrix[0].size(); i++){ // row = x.first, col to iterate
                matrix[x.first][i] = 0;
            }
            for(int i =0; i<matrix.size(); i++){ // col = x.second, row to iterate
                matrix[i][x.second] = 0;
            }
        }

        return;
    }
};
