class Solution {
public:
    set<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        backtrack(candidates, target, curr, 0);
        return vector<vector<int>>(result.begin(), result.end());
    }

    void backtrack(vector<int>& candidates, int target,vector<int>& curr, int i ){
        if (target == 0){
            result.insert(curr);
            return;
        }

        if (target < 0 || i>= candidates.size()){
            return;
        }
        curr.push_back(candidates[i]);
        backtrack(candidates, target-candidates[i], curr, i+1);

        curr.pop_back();
        backtrack(candidates, target, curr, i+1);
    }
};
