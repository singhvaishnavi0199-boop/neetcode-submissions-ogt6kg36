class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> dp(r+1, vector<int> (c+1, 0));

        dp[r-1][c-1] = grid[r-1][c-1];

        for(int i = 0 ; i <=r ; i++){
            dp[i][c] = INT_MAX;
        }
        for(int i = 0 ; i <=c ; i++){
            dp[r][i] = INT_MAX;
        }

        for(int i=r-1; i>=0 ; i--){
            for(int j= c-1 ; j>=0 ; j--){
                if (i== r-1 & j ==c-1){
                    continue;
                }
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }

        return dp[0][0];
    }
};