class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> nums2(nums.begin()+ 1, nums.end());
        dp.assign(nums1.size(), -1);
        int rob1 = dfs(0, nums1);
        dp.assign(nums2.size(), -1);
        int rob2 = dfs(0, nums2);
        return max(rob1, rob2);
    }

    int dfs(int i, vector<int>& nums){
        if (i>=nums.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        dp[i] = max((nums[i]+ dfs(i+2, nums)) , dfs(i+1, nums));
        return dp[i];
    }
};
