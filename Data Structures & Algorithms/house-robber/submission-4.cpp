class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        dp.assign(nums.size()+2, 0);
        for(int i = nums.size()-1 ; i>=0; i--){
            dp[i] = max ((nums[i] + dp[i+2]), dp[i+1]);
        }
        return dp[0];
    }
};
