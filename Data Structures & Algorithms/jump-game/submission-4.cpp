class Solution {
public:
    bool canJump(vector<int>& nums) {
        return dfs (0 , nums);
    }

    bool dfs (int i , vector<int> &nums){
        if (i == nums.size()-1){
            return true;
        }

        bool res = false;
        for(int j = i + 1; (j < nums.size() && j <= i + nums[i]) ; j++ ){
            res = res | dfs (j, nums);
        }
        return res;
    }
};
