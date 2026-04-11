// bottom up approach
class Solution {
public:
    vector<vector<int>> dp;
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        dp.assign(rows+1, vector<int> (cols+1, INT_MAX));

        for(int i = rows-1 ; i>=0 ; i--){
            for(int j = cols-1 ; j>=0 ; j--){
                if (i == rows-1 && j == cols-1){
                    dp[i][j] = grid[i][j];
                }else{
                    dp[i][j] = grid[i][j] + min(dp[i+1][j] , dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};