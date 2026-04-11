class Solution {
public:
    int integerBreak(int n) {
        vector<int> memo (n+1, 0);
        memo[1] = 1;
        return dp (n , memo); 
    }

    int dp (int n , vector <int> &memo){
        if (n == 1){
            return memo[1];
        }

        if (memo[n] != 0){
            return memo[n];
        }

        int res = 0;
        int half = (n + 1) / 2;

        for (int i = 1; i <= half ; i++){
            // res = max (res , max (i * (n-i), dp(i , memo) * dp (n-i, memo)));
            res = max (res, i* (n-i));
            res = max (res , dp(i,memo) * (n-i));
            res = max (res , dp(n-i,memo) * i);
            res = max (res , dp(i,memo) * dp(n-i,memo));
        }

        memo[n] = res;
        return memo[n];
    }

};