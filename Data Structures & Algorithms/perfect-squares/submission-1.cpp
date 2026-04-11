class Solution {
public:
    int numSquares(int n) {

        // memo[n] : least number of perfect square numbers that sum to n
        // this no can be 0 but never -1 , hence initalizing with -1.
        vector<int> memo (n+1, -1);
        return dp(n, memo);
    }

    int dp(int n , vector<int> &memo){
        if (n < 0){
            // != 0 , since it would mean that the no is 1
            return INT_MAX;
        }

        if (n == 0){
            // i need 0 numbers to reach 0
            return 0;
        }

        if (memo[n] != -1){
            return memo[n];
        }

        // worst possible
        memo[n] = INT_MAX;
        int i = 1;
        while (i*i <= n){
            // + 1 is important
            memo[n] = min (memo[n], dp(n- i*i , memo)+1);
            i++;
        }

        return memo[n];
    }
};