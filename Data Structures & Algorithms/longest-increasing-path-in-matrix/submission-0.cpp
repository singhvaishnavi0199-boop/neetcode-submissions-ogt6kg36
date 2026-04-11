class Solution {
    vector<vector<int>> directions = {{0,1}, {1,0} , {0,-1}, {-1,0}};
    int lip = 0;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int> (col, -1));
        for(int r = 0; r< row; r++){
            for(int c =0; c<col; c++){
                lip = max (lip, dfs(matrix, r, c, dp));
            }
        }
        return lip;
    }

private:
    int dfs(vector<vector<int>>& matrix , int r, int c, vector<vector<int>>& dp){
        if (dp[r][c] != -1){
            return dp[r][c];
        }

        int res = 1;
        for(int i= 0; i< directions.size(); i++){
            int nextR = r + directions[i][0];
            int nextC = c + directions[i][1];

            if(nextR < 0 || nextC < 0 || nextR >= matrix.size() || nextC >= matrix[0].size()){
                continue;
            }

            if (matrix[r][c] < matrix[nextR][nextC]){
                res = max( res , 1 + dfs(matrix, nextR, nextC , dp));
            }
        }
        dp[r][c] = res;
        return res;
    }
};
