class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        dp.assign(nums.size()+2, -1);
        return dfs(0, nums);
    }

    int dfs(int i, vector<int>& nums){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        dp[i] = max ((nums[i] + dfs(i+2, nums)), dfs(i+1, nums));
        return dp[i];
    }
};
