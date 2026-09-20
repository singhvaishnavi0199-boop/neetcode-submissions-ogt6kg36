class Solution {
public:
    int dfs ( int amount, vector<int>& coins , vector<int> &dp){
        // base case
        if (amount == 0){
            return 0;
        }

        //memo check
        if(dp[amount] != -1){
            return dp[amount];
        }

        //initialize res;
        dp[amount] = INT_MAX;

        //small calculation
        for(int i = 0; i<coins.size(); i++){
            if(amount- coins[i] >=0){
                int smallCal = dfs(amount-coins[i], coins, dp);
                if(smallCal < INT_MAX){
                    dp[amount] = min(dp[amount] , 1+ smallCal);
                }
            }
        }

        //return
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int res = dfs(amount, coins, dp);
        if (res == INT_MAX){
            return -1;
        }
        return res;
    }
};
