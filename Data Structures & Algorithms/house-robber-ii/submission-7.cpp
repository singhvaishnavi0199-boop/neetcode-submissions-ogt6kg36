class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        vector<int> nums1 (nums.begin() , nums.end()-1); // include first ele
        vector<int> nums2 (nums.begin() + 1, nums.end()); // exclude first ele
        dp.assign(nums1.size(), -1);
        int rob1 = dfs(0, nums1);
        dp.assign(nums2.size(), -1);
        int rob2 = dfs(0, nums2);
        return max(rob1, rob2);
    }

private:
    int dfs(int i, vector<int>& nums){
        if (i>= nums.size()){
            return 0;
        }

        if (dp[i] != -1){
            return dp[i];
        }

        dp[i] = max (dfs(i+1, nums), nums[i] + dfs(i+2, nums));
        return dp[i];
    }
};
