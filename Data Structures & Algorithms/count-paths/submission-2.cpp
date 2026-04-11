// top down approach
class Solution {
public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) {
        dp.assign(m+1, vector<int> (n+1, 0));
        return dfs(0,0,m,n);
    }

    int dfs(int r, int c , int m , int n){
        if (r >m || c >n){
            return 0;
        }

        if (r == m-1 && c == n-1){
            return 1;
        }

        if (dp[r][c] != 0){
            return dp[r][c];
        }

        dp[r][c] = dfs(r+1 , c, m, n) + dfs(r, c+1, m, n);
        return dp[r][c];
    }
};
