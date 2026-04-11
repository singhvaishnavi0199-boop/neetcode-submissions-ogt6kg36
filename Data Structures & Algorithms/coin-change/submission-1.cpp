class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, -1);
        memo[0] = 0;
        int result = dp(coins, amount, memo);
        return result== INT_MAX ? -1 : result;
    }

    int dp(vector<int>& coins, int amount ,vector<int>& memo ){
        if (memo[amount] != -1){
            return memo[amount];
        }

        int result = INT_MAX;

        for(int i= 0; i<coins.size() ; i++){
            if (amount - coins[i] >= 0){
                int sub = dp(coins, amount-coins[i], memo);
                if (sub != INT_MAX){
                    result = min (result, 1+ dp(coins, amount-coins[i], memo));
                }
            }
        }

        memo[amount] = result;
        return result;
    }
};
