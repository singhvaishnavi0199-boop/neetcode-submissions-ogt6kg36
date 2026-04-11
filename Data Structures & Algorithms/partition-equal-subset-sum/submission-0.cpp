class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
        }

        if (sum % 2 != 0){
            return false;
        }

        int target = sum/2;

        vector<vector<int>> memo(nums.size(), vector<int> (target+1, -1));

        return dfs(0,target,memo,nums);
    }

    bool dfs (int i , int target, vector<vector<int>>&memo,vector<int>& nums ){
        if (i == nums.size()){
            return target == 0;
        }

        if(target < 0){
            return false;
        }

        if(memo[i][target] != -1){
            return memo[i][target];
        }

        memo[i][target] = dfs(i+1, target, memo, nums) || dfs(i+1, target-nums[i], memo,nums);
        return memo[i][target];
    }
};
