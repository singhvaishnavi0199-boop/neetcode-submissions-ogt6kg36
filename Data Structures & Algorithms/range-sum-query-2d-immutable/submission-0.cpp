class NumMatrix {
    vector<vector<int>> prefixMat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        prefixMat = vector<vector<int>> (rows+1, vector<int> (cols+1 , 0));

        for(int r= 0 ; r< rows ; r++){
            for(int c = 0; c<cols ; c++){
                prefixMat[r+1][c+1] = matrix[r][c] + 
                                    prefixMat[r+1][c] + 
                                    prefixMat[r][c+1] - 
                                    prefixMat[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixMat[row2+1][col2+1] -
                prefixMat[row1][col2+1] -
                prefixMat[row2+1][col1] + 
                prefixMat[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */