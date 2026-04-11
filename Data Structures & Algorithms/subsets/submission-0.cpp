class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        dfs(nums, result, subset , 0);
        return result;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int i){
        if (i == nums.size()){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums,result, subset, i+1);

        subset.pop_back();
        dfs(nums,result, subset, i+1);
    }
};
