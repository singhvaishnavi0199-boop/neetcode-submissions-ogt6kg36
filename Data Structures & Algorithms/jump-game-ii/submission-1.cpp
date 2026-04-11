class Solution {
public:
    int jump(vector<int>& nums) {
        return dfs(0,nums);
    }

    int dfs(int i, vector<int>& nums){
        if (i == nums.size()-1){
            return 0;
        }

        if(nums[i] == 0){
            return INT_MAX;
        }

        int res = INT_MAX;
        for(int j = i+1; j <nums.size() && j <= i + nums[i] ; j++){
            if (dfs(j,nums) != INT_MAX){
                res = min(res, 1+ dfs(j,nums));
            }
        }
        return res;
    }
};
