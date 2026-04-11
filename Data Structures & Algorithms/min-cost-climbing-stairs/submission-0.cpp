
// 1. recursion
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         return min(dfs(0, cost), dfs(1, cost));
//     }

//     int dfs(int i , vector<int>& cost){
//         if (i >= cost.size()){
//             return 0;
//         }

//         return cost[i] + min (dfs(i+1, cost) , dfs(i+2, cost));
//     }
// };


// 2. top down approach (memoization)
// class Solution{

//     vector<int> memo;
//     public:
//         int minCostClimbingStairs(vector<int> &cost){
//             memo.resize(cost.size(), -1);
//             return min(dfs(cost,0), dfs(cost,1));
//         }

//         int dfs(vector<int> &cost , int i){
//             if(i>= cost.size()){
//                 return 0;
//             }

//             if(memo[i] != -1){
//                 return memo[i];
//             }

//             memo[i] = cost[i] + min(dfs(cost, i+1) , dfs(cost, i+2));
//             return memo[i];
//         }
// };



//3. bottom up approach (tabulation)
class Solution{
    public:
    int minCostClimbingStairs(vector<int> &cost){
        int n  = cost.size();
        vector<int> dp(n+1, 0);
        for(int i=2; i<= n ; i++){
            dp[i] = min(dp[i-1] + cost[i-1] , dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
};
