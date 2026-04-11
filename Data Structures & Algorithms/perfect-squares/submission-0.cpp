class Solution {
public:
    int numSquares(int n) {
        vector<int> memo (n+1, -1);
        return dp(n, memo);
    }

    int dp(int n , vector<int> &memo){
        if (n < 0){
            return INT_MAX;
        }

        if (n == 0){
            return 0;
        }

        if (memo[n] != -1){
            return memo[n];
        }

        memo[n] = INT_MAX;
        int i = 1;
        while (i*i <= n){
            memo[n] = min (memo[n], dp(n- i*i , memo)+1);
            i++;
        }

        return memo[n];
    }
};