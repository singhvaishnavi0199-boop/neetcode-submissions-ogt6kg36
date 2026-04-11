class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0;
        return dfs(0,nums,dp);
    }

    int dfs(int i, vector<int>& nums, vector<int> &dp){
        if (i == nums.size()-1){
            return dp[nums.size()-1];
        }

        if(nums[i] == 0){
            return dp[i];
        }

        if(dp[i] != INT_MAX){
            return dp[i];
        }

        int res = INT_MAX;
        for(int j = i+1; j <nums.size() && j <= i + nums[i] ; j++){
            if (dfs(j,nums,dp) != INT_MAX){
                res = min(res, 1+ dfs(j,nums, dp));
            }
        }

        dp[i] = res;
        return dp[i];
    }
};
