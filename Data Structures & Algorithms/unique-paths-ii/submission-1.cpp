class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();

        vector<vector<int>> dp(r+1, vector<int> (c+1,0));

        for(int i= r-1; i>=0; i--){
            for(int j= c-1 ; j>=0 ; j--){
                if(i==r-1 && j==c-1 && obstacleGrid[i][j]==0){
                    dp[i][j] = 1;
                }
                else if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};