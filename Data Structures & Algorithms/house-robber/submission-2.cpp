class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        // ith home
        // select i and then i+2
        // don't select i and then select from i+1
        int n = nums.size();
        dp.assign(n+1, -1);
        return dfs(0, n, nums);
    }

private:
    int dfs(int i, int n, vector<int>& nums){
        if (i > n-1){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        dp[i] = max((nums[i] + dfs(i+2, n, nums)), dfs(i+1, n, nums));
        return dp[i];
    }
};
