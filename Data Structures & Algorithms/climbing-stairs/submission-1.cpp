class Solution {
public:
    vector<int> dp;
    int climbStairs(int n) {
        dp.assign(n+1 , -1);
        return dfs(0,n);
    }

private:
    int dfs(int i, int n){
        if (i > n){
            return 0;
        }

        if (i == n){
            return 1;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        dp[i] = dfs(i+1, n) + dfs(i+2, n);
        return dp[i];
    }
};