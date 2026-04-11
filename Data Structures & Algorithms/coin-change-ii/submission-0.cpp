class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> memo(coins.size(), vector<int> (amount+1, -1));
        return dfs(0, amount, coins, memo);
    }

private:
    int dfs (int i, int amount , vector<int> &coins, vector<vector<int>> &memo){
        if (amount == 0){
            return 1;
        }

        if (i>=coins.size()){
            return 0;
        }

        if (memo[i][amount]!= -1){
            return memo[i][amount];
        }

        int res = 0;
        if (amount >= coins[i]){
            res = dfs(i, amount-coins[i], coins, memo) + dfs(i+1, amount, coins, memo);
        }
        memo[i][amount] = res;
        return memo[i][amount];
    }
};
