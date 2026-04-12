class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = dfs(coins, amount , dp);
        if (ans == INT_MAX){
            return -1;
        }
        return ans;
    }

    int dfs (vector<int>& coins, int amount, vector<int> &dp){
        if(amount == 0){
            return 0;
        }

        if(dp[amount]!= -1){
            return dp[amount];
        }

        dp[amount] = INT_MAX;

        for(int i = 0; i<coins.size(); i++){
            if (amount - coins[i] >= 0){
                int smallCal = dfs(coins, amount-coins[i], dp);
                if (smallCal < INT_MAX){
                    dp[amount] = min(dp[amount] , 1+ smallCal);
                }
            }
        }

        return dp[amount];
    }
};


/*
dp[x] = min coins that sum to x

for (int i = 0; i< coins.size(); i++){
    dp[x] = min (dp[x] , 1 + dp[x - coins[i]]);
}

return dp[x];
*/
