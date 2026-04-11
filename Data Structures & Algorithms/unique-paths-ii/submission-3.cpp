class Solution {
public:
    vector<vector<int>> dp;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        dp.assign(rows+1, vector<int> (cols+1 , -1));
        return dfs(0,0,obstacleGrid);
    }

    int dfs(int r, int c, vector<vector<int>>& obstacleGrid){
        if (r == obstacleGrid.size()-1 && c == obstacleGrid[0].size()-1 && obstacleGrid[r][c]==0){
            return 1;
        }

        if (r >= obstacleGrid.size() || c >= obstacleGrid[0].size()){
            return 0;
        }

        if (obstacleGrid[r][c] == 1){
            return 0;
        }

        if(dp[r][c] != -1){
            return dp[r][c];
        }

        dp[r][c] = dfs(r+1, c, obstacleGrid) + dfs(r, c+1, obstacleGrid);
        return dp[r][c];
    }
};