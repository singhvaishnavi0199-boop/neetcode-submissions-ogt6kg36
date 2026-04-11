class Solution {
    int m;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i =0; i<n ; i++){
            m += nums[i];
        }
        vector<vector<int>> memo(n , vector<int> (2*m+1 , INT_MIN));

        return dp(0, 0, target , nums, memo);
    }

private:
    int dp(int i , int total , int target , vector<int> &nums, vector<vector<int>> &memo){
        if (i >= nums.size()){
            return total == target ? 1 : 0;
        }

        int idx = total + m;  // shifted index

        if (memo[i][idx] != INT_MIN){
            return memo[i][idx];
        }

        memo[i][idx] = dp(i+1, total+nums[i], target, nums, memo) + dp(i+1, total-nums[i], target , nums, memo);
        return memo[i][idx];

    }
};
