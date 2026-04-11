class Solution {
public:
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n+1, -1);
        return min(dfs(0,n, cost), dfs(1,n, cost));
    }

    int dfs(int i, int n ,vector<int>& cost){

        if(i>=n){
            return 0;
        }

        // if (i==n){
        //     return 
        // }


        if(dp[i] != -1){
            return dp[i];
        }

        dp[i] = cost[i] + min(dfs(i+1, n, cost), dfs(i+2, n, cost));
        return dp[i];
    }
};
