class Solution {
public:
    vector<int> dp; // dp[i] represents min cost to go from ith step to the top
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); // 0, 1, 2,...n-1
        dp.assign(n, -1);
        return min (dfs(0,n , cost), dfs(1,n, cost));
    }

    int dfs(int i, int n, vector<int>& cost){
        if (i==(n-1)){ // base case
            return cost[n-1];
        }

        if (i >= n){ // out of bounds
            return 0;
        }

        if (dp[i] != -1){
            return dp[i];
        }

        dp[i] = cost[i] + min(dfs(i+1, n, cost), dfs(i+2, n, cost));
        return dp[i];
    }
};
