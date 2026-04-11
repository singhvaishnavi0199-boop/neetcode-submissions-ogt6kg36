class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target+1 , -1);
        // memo[0], memo[1] , memo[2], memo[3] , memo[4]
        // memo[4] is returned
        return dp(nums, target, memo);
    }

    int dp(vector<int> &nums, int target , vector<int> &memo){
        if (target < 0){
            return 0;
        }
        
        if (target== 0){
            return 1;
            }
            
        if (memo[target] != -1){
            return memo[target];
        }

        memo[target] = 0;
        for(int i = 0; i< nums.size(); i++){
            memo[target] += dp(nums, target - nums[i],memo);
        }
            
        return memo[target];
    }
};