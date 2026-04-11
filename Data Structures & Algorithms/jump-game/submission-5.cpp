class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, -1);
        dp[n-1] = true;
        return dfs (0 , nums, dp);
    }

    bool dfs (int i , vector<int> &nums, vector<int>& dp){
        if (i == nums.size()-1){
            return dp[nums.size()-1];
        }
        if (dp[i] != -1){
            return dp[i];
        }
        bool res = false;
        for(int j = i + 1; (j < nums.size() && j <= i + nums[i]) ; j++ ){
            res = res | dfs (j, nums , dp);
        }
        dp[i] = res;
        return res;
    }
};
